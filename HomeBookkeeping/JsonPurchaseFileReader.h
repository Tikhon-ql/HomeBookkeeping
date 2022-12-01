#pragma once
#include "PurchaseFileReader.h"
#include <list>	

class JsonPurchaseFileReader : public PurchaseFileReader
{
public:
	//std::string LoadFromFile(std::string path);
	void SaveToFile(std::string path, std::list<Purchase*> members);
};