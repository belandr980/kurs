#include "reklamabase.h"
ReklamaBase::ReklamaBase()
{
	filename = "reklamabase.csv";
	int reklama_id, zena, month;
	std::string vid, name, surname,\
		father_name, expanded, mesto;
	std::ifstream file;
	file.open(filename);
	std::string reklama_line;
	try 
	{
		if (file.is_open()) {
			while (std::getline(file, reklama_line))
			{
				std::stringstream reklama_stream(reklama_line);
				std::string str_part;

				std::getline(reklama_stream, str_part, ';');
				reklama_id = stoi(str_part);

				std::getline(reklama_stream, str_part, ';');
				vid = str_part;

				std::getline(reklama_stream, str_part, ';');
				surname = str_part;

				std::getline(reklama_stream, str_part, ';');
				name = str_part;

				std::getline(reklama_stream, str_part, ';');
				father_name = str_part;

				std::getline(reklama_stream, str_part, ';');
				mesto = str_part;

				std::getline(reklama_stream, str_part, ';');
				expanded = str_part;

				std::getline(reklama_stream, str_part, ';');
				zena = stoi(str_part);

				std::getline(reklama_stream, str_part, ';');
				month = stoi(str_part);
				Reklama reklama(reklama_id, vid, name, surname, father_name, mesto, expanded, zena, month);
				reklama_base.push_back(reklama);
			}
		}
	}
	catch (std::exception ex)
	{
		std::cout << "Возникла проблемы. " <<\
			"Программа приостановлена." << std::endl;
		system("pause");
		exit(0);
	}
	file.close();
}


size_t ReklamaBase::GetSize() const
{
	return reklama_base.size();
}

std::string ReklamaBase::GetFileName() const
{
	return filename;
}

void ReklamaBase::SaveToFile()
{
	std::ofstream file;
	file.open(filename);
	for (int i = 0; i < reklama_base.size(); i++)
	{
		file << std::to_string(reklama_base[i].GetReklamaId()) + ";" + \
			reklama_base[i].GetVid() + ";" + \
			reklama_base[i].GetSurname() + ";" + \
			reklama_base[i].GetName() + ";" + \
			reklama_base[i].GetFatherName() + ";" + \
			reklama_base[i].GetMesto() + ";" + \
			reklama_base[i].GetExpanded() + ";" + \
			std::to_string(reklama_base[i].GetZena()) + ";" + \
			std::to_string(reklama_base[i].GetMonth()) << std::endl;
	}
	file.close();
}

void ReklamaBase::AllPrint() const
{
	for (int i = 0; i < reklama_base.size(); i++)
	{
		std::cout << reklama_base[i].GetReklamaId() << " " << \
			reklama_base[i].GetVid() << " " << \
			reklama_base[i].GetSurname() << " " << \
			reklama_base[i].GetName() << " " << \
			reklama_base[i].GetFatherName() << " " << \
			reklama_base[i].GetMesto() << " " << \
			reklama_base[i].GetExpanded() << " " << \
			reklama_base[i].GetZena() << " " << \
			reklama_base[i].GetMonth() << std::endl;
	}
}

void ReklamaBase::PrintById(int reklama_id) const
{
	for (int i = 0; i < reklama_base.size(); i++)
	{
		if (reklama_id == -1) break;
		if (reklama_base[i].GetReklamaId() == reklama_id)
		{
			std::cout << reklama_base[i].GetReklamaId() << " " << \
				reklama_base[i].GetVid() << " " << \
				reklama_base[i].GetSurname() << " " << \
				reklama_base[i].GetName() << " " << \
				reklama_base[i].GetFatherName() << " " << \
				reklama_base[i].GetMesto() << " " << \
				reklama_base[i].GetExpanded() << " " << \
				reklama_base[i].GetZena() << " " << \
				reklama_base[i].GetMonth() << std::endl;
		}
	}
}

void ReklamaBase::AddReklama(Reklama reklama)
{
	reklama_base.push_back(reklama);
}

void ReklamaBase::EditReklama(int reklama_id, Reklama reklama)
{
	for (int i = 0; i < reklama_base.size(); i++)
	{
		if (reklama_id == reklama_base[i].GetReklamaId()) reklama_base[i] = reklama;
	}
}

void ReklamaBase::DeleteReklamaById(int reklama_id)
{
	reklama_base.erase(reklama_base.begin() + reklama_id - 1);
	for (int i = 0; i < reklama_base.size(); i++)
	{
		reklama_base[i].SetReklamaId(i + 1);
	}
}

void ReklamaBase::Clear()
{
	reklama_base.clear();
}

//Сортировка
static bool sortByVidUpper(const Reklama left, const Reklama right)
{
	return left.GetVid() < right.GetVid();
}

static bool sortByVidLower(const Reklama left, const Reklama right)
{
	return left.GetVid() > right.GetVid();
}

static bool sortByNameUpper(const Reklama left, const Reklama right)
{
	return left.GetName() < right.GetName();
}

static bool sortByNameLower(const Reklama left, const Reklama right)
{
	return left.GetName() > right.GetName();
}

static bool sortBySurnameUpper(const Reklama left, const Reklama right)
{
	return left.GetSurname() < right.GetSurname();
}

static bool sortBySurnameLower(const Reklama left, const Reklama right)
{
	return left.GetSurname() > right.GetSurname();
}

static bool sortByFatherNameUpper(const Reklama left, const Reklama right)
{
	return left.GetFatherName() < right.GetFatherName();
}

static bool sortByFatherNameLower(const Reklama left, const Reklama right)
{
	return left.GetFatherName() > right.GetFatherName();
}

static bool sortByMestoUpper(const Reklama left, const Reklama right)
{
	return left.GetMesto() < right.GetMesto();
}

static bool sortByMestoLower(const Reklama left, const Reklama right)
{
	return left.GetMesto() > right.GetMesto();
}

static bool sortByExpandedUpper(const Reklama left, const Reklama right)
{
	return left.GetExpanded() < right.GetExpanded();
}

static bool sortByExpandedLower(const Reklama left, const Reklama right)
{
	return left.GetExpanded() > right.GetExpanded();
}

static bool sortByZenaUpper(const Reklama left, const Reklama right)
{
	return left.GetZena() < right.GetZena();
}

static bool sortByZenaLower(const Reklama left, const Reklama right)
{
	return left.GetZena() > right.GetZena();
}

static bool sortByMonthUpper(const Reklama left, const Reklama right)
{
	return left.GetMonth() < right.GetMonth();
}

static bool sortByMonthLower(const Reklama left, const Reklama right)
{
	return left.GetMonth() > right.GetMonth();
}

void ReklamaBase::GetSorted(std::string field_name, char type)
{
	if (field_name == "vid" && type == 'U')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByVidUpper);
	}

	if (field_name == "vid" && type == 'L')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByVidLower);
	}

	if (field_name == "name" && type == 'U')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByNameUpper);
	}

	if (field_name == "name" && type == 'L')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByNameLower);
	}

	if (field_name == "surname" && type == 'U')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortBySurnameUpper);
	}

	if (field_name == "surname" && type == 'L')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortBySurnameLower);
	}

	if (field_name == "father_name" && type == 'U')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByFatherNameUpper);
	}

	if (field_name == "father_name" && type == 'L')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByFatherNameLower);
	}

	if (field_name == "mesto" && type == 'U')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByMestoUpper);
	}

	if (field_name == "mesto" && type == 'L')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByMestoLower);
	}

	if (field_name == "expanded" && type == 'U')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByExpandedUpper);
	}

	if (field_name == "expanded" && type == 'L')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByExpandedLower);
	}

	if (field_name == "zena" && type == 'U')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByZenaUpper);
	}

	if (field_name == "zena" && type == 'L')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByZenaLower);
	}

	if (field_name == "month" && type == 'U')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByMonthUpper);
	}

	if (field_name == "month" && type == 'L')
	{
		std::sort(begin(reklama_base), end(reklama_base), sortByMonthLower);
	}
}