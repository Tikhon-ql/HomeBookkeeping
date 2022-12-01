#pragma once
#include "FamilyFileReader.h"
#include <list>	

class JsonFamilyFileReader : public FamilyFileReader
{
public:
	//std::string LoadFromFile(std::string path);
	void SaveToFile(std::string path, std::list<FamilyMember*> members);
};