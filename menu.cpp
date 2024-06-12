#include "menu.h"

int choice, reklama_id, zena, month;
std::string input_choice, input_reklama_id, vid,\
name, surname, father_name,\
mesto, expanded,\
input_password, input_zena, input_month;

Menu::Menu()
{
	std::fstream file("config/password.txt");
	std::getline(file, password);
	file.close();
	password_status = false;
	file.open("config/color.txt");
	std::string color;
	std::getline(file, color);
	file.close();
	const char* p_color = color.c_str();
	system(p_color);
}

void Menu::MenuName() {
	std::cout << "������ ����� �������, ������������ � ��������� ��������" << std::endl;
}

void Menu::Start(Menu& menu, ReklamaBase& reklama_base) {
	system("cls");
	menu.MenuName();
	std::cout << "����� ���:" << std::endl \
		<< "1. ������������" << std::endl << "2. �������������" << std::endl << "3. �����" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		system("cls");
		std::cout << "������� ���������� �����." << std::endl;
		system("pause");
		menu.Start(menu, reklama_base);
	}
	switch (choice)
	{
	case 1:
		menu.UserMenu(menu, reklama_base);
		break;
	case 2:
		menu.AdminMenu(menu, reklama_base);
		break;
	case 3:
		menu.Exit(reklama_base);
		break;
	default:
		system("cls");
		std::cout << "����� ������� �� ����������." << std::endl;
		system("pause");
		menu.Start(menu, reklama_base);
		break;
	}
}

void Menu::InputReklamaId()
{
	std::cout << "������� �������������" << std::endl << ">> ";
	std::cin >> input_reklama_id;
	try
	{
		reklama_id = stoi(input_reklama_id);
	}
	catch (std::exception ex)
	{
		std::cout << "������� ���������� �����." << std::endl;
	}
}

void Menu::NoneReklamaId(Menu& menu, ReklamaBase& reklama_base, char type)
{
	if (reklama_id > reklama_base.GetSize() || reklama_id < 1) {
		std::cout << "�������� � ����� ��������������� �� ���������." << std::endl;
		system("pause");
		if (type == 'A') menu.AdminMenu(menu, reklama_base);
		else menu.UserMenu(menu, reklama_base);
	}
}

void Menu::UserMenu(Menu& menu, ReklamaBase& reklama_base)
{
	system("cls");
	std::cout << "������������" << std::endl \
		<< "1. ���� �������" << std::endl\
		<< "2. ���������� �� ����� �������" << std::endl\
		<< "3. ����������" << std::endl\
		<< "4. ����� �����" << std::endl\
		<< "5. �����" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "������� ���������� �����." << std::endl;
		system("pause");
		menu.UserMenu(menu, reklama_base);
	}
	switch (choice)
	{
	case 1:
		system("cls");
		reklama_base.AllPrint();
		system("pause");
		menu.UserMenu(menu, reklama_base);
		break;
	case 2:
		system("cls");
		reklama_id = -1;
		menu.InputReklamaId();
		menu.NoneReklamaId(menu, reklama_base, 'U');
		reklama_base.PrintById(reklama_id);
		system("pause");
		menu.UserMenu(menu, reklama_base);
		break;
	case 3:
		menu.MenuSort(menu, reklama_base, 'U');
		break;
	case 4:
		menu.ChangeColor(menu, reklama_base, 'U');
		break;
	case 5:
		menu.Start(menu, reklama_base);
		break;
	default:
		system("cls");
		std::cout << "����� ������� �� ����������." << std::endl;
		system("pause");
		menu.UserMenu(menu, reklama_base);
		break;
	}
}

void Menu::AdminMenu(Menu& menu, ReklamaBase& reklama_base)
{
	system("cls");
	if (password_status == false) { menu.InputPassword(menu, reklama_base); };
	menu.MenuName();
	std::cout << "����� ������: �������������" << std::endl << \
		"1. ���� �������" << std::endl << "2. ���������� �� ����� �������" << std::endl << \
		"3. �������� ����� ��� �������" << std::endl << "4. ������������� ���������� � �������" << std::endl << "5. �������� ������" << \
		std::endl << "6. ������� ������� �� ������" << std::endl << "7. �������� ������" << std::endl << "8. ���������� ������" << std::endl << "9. C�������� ����" << std::endl \
		<< "10. ����� �����" << std::endl << "11. �����" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "������� ���������� �����." << std::endl;
		system("pause");
		menu.AdminMenu(menu, reklama_base);
	}
	switch (choice)
	{
	case 1:
		system("cls");
		reklama_base.AllPrint();
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	case 2:
		system("cls");
		reklama_id = -1;
		menu.InputReklamaId();
		menu.NoneReklamaId(menu, reklama_base, 'A');
		reklama_base.PrintById(reklama_id);
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	case 3:
	{
		system("cls");
		menu.AddInfo(menu, reklama_base);
		if (reklama_base.GetSize() == 0) {
			reklama_id = 1;
		}
		else {
			reklama_id = reklama_base.GetSize() + 1;
		}
		Reklama reklama(reklama_id, vid,\
			name, surname, father_name,\
			mesto, expanded,\
			zena, month);
		reklama_base.AddReklama(reklama);
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	}
	case 4: {
		system("cls");
		reklama_id = -1;
		menu.InputReklamaId();
		menu.NoneReklamaId(menu, reklama_base, 'A');
		if (reklama_id < 1) {
			system("pause");
			menu.AdminMenu(menu, reklama_base);
		}
		std::cout << "������ ������ � ����������" << std::endl;
		reklama_base.PrintById(reklama_id);
		std::cout << "����� ������ � ����������" << std::endl;
		menu.AddInfo(menu, reklama_base);
		Reklama reklama(reklama_id, vid, name, surname, father_name, mesto, expanded, zena, month);
		reklama_base.EditReklama(reklama_id, reklama);
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	}
	case 5:
		menu.ChangePassword(menu, reklama_base);
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	case 6:
		system("cls");
		reklama_id = -1;
		menu.InputReklamaId();
		menu.NoneReklamaId(menu, reklama_base, 'A');
		std::cout << "������� �����" << std::endl;
		reklama_base.DeleteReklamaById(reklama_id);
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	case 7:
		system("cls");
		reklama_base.Clear();
		std::cout << "������ ������" << std::endl;
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	case 8:
		menu.MenuSort(menu, reklama_base, 'A');
		break;
	case 9:
		system("cls");
		reklama_base.SaveToFile();
		std::cout << "������ ��������" << std::endl;
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	case 10:
		menu.ChangeColor(menu, reklama_base, 'A');
		break;
	case 11:
		menu.Start(menu, reklama_base);
		break;
	default:
		system("cls");
		std::cout << "����� ������� �� ����������." << std::endl;
		system("pause");
		menu.AdminMenu(menu, reklama_base);
		break;
	}
}

void Menu::AddInfo(Menu& menu, ReklamaBase& reklama_base)
{
	std::cout << "��� ������������� ����������� quit ��� ���������������� ������" << std::endl;
	std::cout << "������� �����: " << std::endl << ">> ";
	std::cin >> vid;
	if (vid == "quit") menu.AdminMenu(menu, reklama_base);
	std::cout << "������� ������� ��������������: " << std::endl << ">> ";;
	std::cin >> surname;
	if (surname == "quit") menu.AdminMenu(menu, reklama_base);
	std::cout << "������� ��� ��������������: " << std::endl << ">> ";;
	std::cin >> name;
	if (name == "quit") menu.AdminMenu(menu, reklama_base);
	std::cout << "������� �������� ��������������: " << std::endl << ">> ";;
	std::cin >> father_name;
	if (father_name == "quit") menu.AdminMenu(menu, reklama_base);
	std::cout << "������� ����� ���������� �������: " << std::endl << ">> ";;
	std::cin >> mesto;
	if (mesto == "quit") menu.AdminMenu(menu, reklama_base);
	std::cout << "������� ����������� ��� ���������� �������: " << std::endl << ">> ";;
	std::cin >> expanded;
	if (expanded == "quit") menu.AdminMenu(menu, reklama_base);
	std::cout << "������� ����: " << std::endl << ">> ";;
	std::cin >> input_zena;
	if (input_zena == "quit") menu.AdminMenu(menu, reklama_base);
	try
	{
		zena = stoi(input_zena);
	}
	catch (std::exception ex)
	{
		std::cout << "������� ���������� �����." << std::endl;
		system("pause");
		menu.AdminMenu(menu, reklama_base);
	}
	if (zena < 0) {
		std::cout << "������� �� ������ ����." << std::endl;
		system("pause");
		menu.AdminMenu(menu, reklama_base);
	}
	std::cout << "������� ���-�� ������� ������: " << std::endl << ">> ";
	std::cin >> input_month;
	try
	{
		month = stoi(input_month);
	}
	catch (std::exception ex)
	{
		std::cout << "������� ���������� �����." << std::endl;
		system("pause");
		menu.AdminMenu(menu, reklama_base);
	}
	if (month < 0) {
		std::cout << "������������� ����� �� ���������." << std::endl;
		system("pause");
		menu.AdminMenu(menu, reklama_base);
	}
}

void Menu::InputPassword(Menu& menu, ReklamaBase& reklama_base)
{
	system("cls");
	menu.MenuName();
	std::cout << "������� ������: " << std::endl << ">> ";
	std::cin >> input_password;
	while (true) {
		if (password == input_password) 
		{ 
			system("cls"); 
			password_status = true; 
			break; 
		}
		std::cout << "�� ������� ����� ������. " <<\
			"���������� �����" <<  std::endl\
			<< "��� ������ ����������� quit" << std::endl << ">> ";
		std::cin >> input_password;
		if (input_password == "quit") menu.Start(menu, reklama_base);
	}
}

void Menu::ChangePassword(Menu& menu, ReklamaBase& reklama_base)
{
	system("cls");
	menu.MenuName();
	std::cout << "������� ������ ������: " << std::endl << ">> ";
	std::cin >> input_password;
	while (true)
	{
		if (password == input_password) { password_status = false; break; };
		std::cout << "�� ������� ����� ������, ���������� ����� (��� ������ ����������� quit): " << std::endl << ">> ";
		std::cin >> input_password;
		if (input_password == "quit") menu.AdminMenu(menu, reklama_base);
	}
	std::cout << "������� ����� ������: " << std::endl << ">> ";
	std::cin >> input_password;
	password = input_password;
	std::ofstream file;
	file.open("config/password.txt");
	file << password;
	file.close();
}

void Menu::SetColor(Menu& menu, const char* color)
{
	system(color);
	std::ofstream file;
	file.open("config/color.txt");
	file << color;
	file.close();
}

void Menu::ChangeColor(Menu& menu, ReklamaBase& reklama_base, const char access)
{
	system("cls");
	std::cout << "�������� ����� ����������" << std::endl << "1. ������ ����" << std::endl << "2. ����� ����" << std::endl << \
		"3. ������ ����, ����� �����" << std::endl << "4. ����� ����, ����� �����" << std::endl << "5. ������ ����, ����� ������" << std::endl << "6. �����" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "������� ���������� �����." << std::endl;
		system("pause");
		menu.ChangeColor(menu, reklama_base, access);
	}
	switch (choice)
	{
	case 1:
		menu.SetColor(menu, "color 0F");
		system("cls");
		std::cout << "����� ���������� ������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, reklama_base, access);
		break;
	case 2:
		menu.SetColor(menu, "color F0");
		system("cls");
		std::cout << "����� ���������� ������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, reklama_base, access);
		break;
	case 3:
		menu.SetColor(menu, "color 03");
		system("cls");
		std::cout << "����� ���������� ������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, reklama_base, access);
		break;
	case 4:
		menu.SetColor(menu, "color F3");
		system("cls");
		std::cout << "����� ���������� ������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, reklama_base, access);
		break;
	case 5:
		menu.SetColor(menu, "color 02");
		system("cls");
		std::cout << "����� ���������� ������" << std::endl;
		system("pause");
		menu.ChangeColor(menu, reklama_base, access);
		break;
	case 6:
		if (access == 'A') menu.AdminMenu(menu, reklama_base);
		else menu.UserMenu(menu, reklama_base);
		break;
	default:
		system("cls");
		std::cout << "����� ������� �� ����������." << std::endl;
		system("pause");
		menu.ChangeColor(menu, reklama_base, access);
		break;
	}
}

void Menu::MenuSort(Menu& menu, ReklamaBase& reklama_base, const char& access)
{
	system("cls");
	menu.MenuName();
	std::cout << "�������� ���� ����������"\
		<< std::endl << "1. ���" << std::endl << "2. ������� ��������������"\
		<< std::endl << "3. ��� ��������������" << std::endl << "4. �������� ��������������"\
		<< std::endl << "5. ����� ���������� �������" << std::endl << "6. ����������� ��� ���������� �������" << std::endl << "7. ����"\
		<< std::endl << "8. ���-�� ������� ������" << std::endl << "9. �����" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "������� ���������� �����." << std::endl;
		system("pause");
		menu.MenuSort(menu, reklama_base, access);
	}
	switch (choice)
	{
	case 1:
		menu.MenuTypeSort(menu, reklama_base, "vid", access);
		break;
	case 2:
		menu.MenuTypeSort(menu, reklama_base, "surname", access);
		break;
	case 3:
		menu.MenuTypeSort(menu, reklama_base, "name", access);
		break;
	case 4:
		menu.MenuTypeSort(menu, reklama_base, "father_name", access);
		break;
	case 5:
		menu.MenuTypeSort(menu, reklama_base, "mesto", access);
	case 6:
		menu.MenuTypeSort(menu, reklama_base, "expanded", access);
		break;
	case 7:
		menu.MenuTypeSort(menu, reklama_base, "zena", access);
		break;
	case 8:
		menu.MenuTypeSort(menu, reklama_base, "month", access);
		break;
	case 9:
		if (access == 'A') menu.AdminMenu(menu, reklama_base);
		else menu.UserMenu(menu, reklama_base);
		break;
	default:
		system("cls");
		std::cout << "����� ������� �� ����������." << std::endl;
		system("pause");
		menu.MenuSort(menu, reklama_base, access);
		break;
	}
}

void Menu::MenuTypeSort(Menu& menu, ReklamaBase& reklama_base, std::string field_name, const char& access)
{
	system("cls");
	std::cout << "���������� �� ����: "\
		<< field_name << std::endl <<\
		"1. �� �����������" << std::endl << "2. �� ��������"\
		<< std::endl << "3. �����" << std::endl << ">> ";
	std::cin >> input_choice;
	try
	{
		choice = stoi(input_choice);
	}
	catch (std::exception ex)
	{
		std::cout << "������� ���������� �����." << std::endl;
		system("pause");
		menu.MenuTypeSort(menu, reklama_base, field_name, access);
	}
	ReklamaBase sort_reklama_base = reklama_base;
	switch (choice)
	{
	case 1:
		sort_reklama_base.GetSorted(field_name, 'U');
		sort_reklama_base.AllPrint();
		system("pause");
		menu.MenuTypeSort(menu, reklama_base, field_name, access);
		break;
	case 2:
		sort_reklama_base.GetSorted(field_name, 'L');
		sort_reklama_base.AllPrint();
		system("pause");
		menu.MenuTypeSort(menu, reklama_base, field_name, access);
		break;
	case 3:
		menu.MenuSort(menu, reklama_base, access);
		break;
	default:
		system("cls");
		std::cout << "����� ������� �� ����������." << std::endl;
		system("pause");
		menu.MenuTypeSort(menu, reklama_base, field_name, access);
		break;
	}
}

void Menu::Exit(ReklamaBase& reklama_base)
{
	reklama_base.SaveToFile();
	exit(0);
}
