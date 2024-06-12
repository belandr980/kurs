#pragma once
#include <string>
class Reklama
{
private:
	int reklama_id;
	std::string vid;
	std::string name;
	std::string surname;
	std::string father_name;
	std::string mesto;
	std::string expanded;
	int zena;
	int month;
public:
	Reklama(int reklama_id, std::string vid,\
		std::string name, std::string surname,\
		std::string father_name,\
		std::string mesto, std::string expanded,\
		int zena, int month);
	int GetReklamaId() const;
	void SetReklamaId(int reklama_id);
	std::string GetVid() const;
	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetFatherName() const;
	std::string GetMesto() const;
	std::string GetExpanded() const;
	int GetZena() const;
	int GetMonth() const;
};

