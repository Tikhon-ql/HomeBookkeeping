#pragma once
#include "FamilyMember.h"
#include "FamilyFactory.h"
#include "JobFactory.h"
#include <list>

class Family
{
private:
	std::list<FamilyMember*> _familyMembers = std::list<FamilyMember*>();
	FamilyFactory* _familyFactory;
	JobFactory* _jobFactory;
public:
	Family();
	void AddMember(FamilyMember* member);
	void RemoveMember(int id);
	void showAll();
	void LoadFromFile(std::string path);
	void SaveToFile(std::string path);
	void SetFamilyFactory(FamilyFactory* factory) { _familyFactory = factory; }
	void SetJobFactory(JobFactory* factory) { _jobFactory = factory; }
};