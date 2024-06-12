#include "reklama.h"

Reklama::Reklama(int reklama_id, std::string vid,\
	std::string name, std::string surname,\
	std::string father_name,\
	std::string mesto, std::string expanded,\
	int zena, int month)
{
	this->reklama_id = reklama_id;
	this->vid = vid;
	this->name = name;
	this->surname = surname;
	this->father_name = father_name;
	this->mesto = mesto;
	this->expanded = expanded;
	this->zena = zena;
	this->month = month;
}

int Reklama::GetReklamaId() const
{
	return reklama_id;
}

void Reklama::SetReklamaId(int reklama_id)
{
	this->reklama_id = reklama_id;
}

std::string Reklama::GetVid() const
{
	return vid;
}	

std::string Reklama::GetName() const
{
	return name;
}

std::string Reklama::GetSurname() const
{
	return surname;
}

std::string Reklama::GetFatherName() const
{
	return father_name;
}

std::string Reklama::GetMesto() const
{
	return mesto;
}

std::string Reklama::GetExpanded() const
{
	return expanded;
}

int Reklama::GetZena() const
{
	return zena;
}

int Reklama::GetMonth() const
{
	return month;
}
