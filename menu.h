#pragma once
#include "reklamabase.h"
#include <string>
#include <iostream>
class Menu
{
private:
	std::string password;
	bool password_status;
public:
	Menu();
	void MenuName();
	void InputReklamaId();
	void NoneReklamaId(Menu& menu, ReklamaBase& reklama_base, char type);
	void Start(Menu& menu, ReklamaBase& reklama_base);
	void UserMenu(Menu& menu, ReklamaBase& reklama_base);
	void AdminMenu(Menu& menu, ReklamaBase& reklama_base);
	void AddInfo(Menu& menu, ReklamaBase& reklama_base);
	void InputPassword(Menu& menu, ReklamaBase& reklama_base);
	void ChangePassword(Menu& menu, ReklamaBase& reklama_base);
	void SetColor(Menu& menu, const char* color);
	void ChangeColor(Menu& menu, ReklamaBase& reklama_base,\
		const char access);
	void MenuSort(Menu& menu, ReklamaBase& reklama_base,\
		const char& access);
	void MenuTypeSort(Menu& menu, ReklamaBase& reklama_base,\
		std::string field_name, const char& access);
	void Exit(ReklamaBase& reklama_base);
};
