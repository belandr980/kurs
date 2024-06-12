#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "reklama.h"
#include <algorithm>
class ReklamaBase
{
private:
	std::vector<Reklama> reklama_base;
	std::string filename;
public:
	ReklamaBase();
	size_t GetSize() const;
	std::string GetFileName() const;
	void SaveToFile();
	void AllPrint() const;
	void PrintById(int reklama_id) const;
	void AddReklama(Reklama reklama);
	void EditReklama(int reklama_id, Reklama reklama);
	void DeleteReklamaById(int reklama_id);
	void Clear();
	void GetSorted(std::string field_name, char type);
};
