#pragma once
#include "FamilyMember.h"
#include "FamilyFactory.h"
#include "FileReader.h"
#include "JobFileReader.h"
#include "PurchaseFileReader.h"
#include <string>
#include <list>

class FamilyFileReader : public FileReader<std::list<FamilyMember*>>
{
protected:
	JobFileReader* _jobReader;
	PurchaseFileReader* _purchaseReader;
public:
	std::string LoadFromFile(std::string path)override { return FileReader<std::list<FamilyMember*>>::LoadFromFile(path); };
	void virtual SaveToFile(std::string path, std::list<FamilyMember*> members) = 0;
	void SetJobReader(JobFileReader* reader);
	void SetPurchaseReader(PurchaseFileReader* reader);
};