#define _CRT_SECURE_NO_WARNINGS

#include "Family.h"
#include "WorkingFamilyMember.h"
#include "FamilyFileReader.h"
#include "JsonFamilyFileReader.h"
#include "JsonJobFileReader.h"
#include "JsonPurchaseFileReader.h"
#include <fstream>
#include <iostream>


using namespace std;

Family::Family() {};

void Family::AddMember(FamilyMember* member) { _familyMembers.push_back(member); }

void Family::RemoveMember(int id)
{
	list<FamilyMember*>::iterator iter = _familyMembers.begin();
	for (auto f : _familyMembers)
	{
		if (f->GetId() == id)
		{
			_familyMembers.erase(iter);
		}
		iter++;
	}
}

void Family::SaveToFile(std::string path)
{
	FamilyFileReader* familyReader = new JsonFamilyFileReader();
	JobFileReader* jobReader = new JsonJobFileReader();
	PurchaseFileReader* purchaseReader = new JsonPurchaseFileReader();
	familyReader->SetJobReader(jobReader);
	familyReader->SetPurchaseReader(purchaseReader);

	familyReader->SaveToFile(path, _familyMembers);
	list<Job*> jobs;
	list<Purchase*> purchases;
	for (auto f : _familyMembers)
	{
		if (f->type == Adult)
		{
			for (auto j : static_cast<WorkingFamilyMember*>(f)->GetJobs())
			{
				jobs.push_back(j);
			}
		}
		for (auto p : f->GetPurchases())
		{
			purchases.push_back(p);
		}
	}
	jobReader->SaveToFile("jobs.json", jobs);
	purchaseReader->SaveToFile("purchases.json", purchases);
}

void Family::LoadFromFile(std::string path)
{
	FamilyFileReader* familyReader = new JsonFamilyFileReader();
	JobFileReader* jobReader = new JsonJobFileReader();
	string familyJson = familyReader->LoadFromFile(path);
	string jobJson = jobReader->LoadFromFile("jobs.json");
	_familyMembers = _familyFactory->Create(familyJson);
	list<Job*> jobs = _jobFactory->Create(jobJson);
}


void Family::showAll()
{
	for (auto m : _familyMembers)
	{
		cout << m->ToString() << endl;
	}
}