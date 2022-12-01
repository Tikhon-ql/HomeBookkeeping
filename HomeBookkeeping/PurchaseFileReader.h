#pragma once
#include "FileReader.h"
#include "Job.h"
#include "Purchase.h"
#include <string>
#include <list>

class PurchaseFileReader : FileReader<std::list<Purchase*>>
{
public:
	std::string virtual LoadFromFile(std::string path) { return FileReader<std::list<Purchase*>>::LoadFromFile(path); };
	void virtual SaveToFile(std::string path, std::list<Purchase*> jobs) = 0;
};