#include "JsonFamilyFileReader.h"
#include "WorkingFamilyMember.h"
#include <string>
#include <list>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

void JsonFamilyFileReader::SaveToFile(string path, list<FamilyMember*> members)
{
	ofstream fout;
	fout.open(path, ios_base::out);
	json memberJsonArray = json::array();
	json memberJson;
	for (auto f : members)
	{
		memberJson["username"] = f->GetUsername();
		memberJson["name"] = f->GetName();
		memberJson["surname"] = f->GetSurname();
		memberJson["currentBalance"] = f->GetCurrentBalance();
		if (f->type == Adult)
		{
			/*memberJson["type"] = 1;
			memberJson["totalSalary"] = static_cast<WorkingFamilyMember*>(f)->GetTotalSalary();
			_jobReader->SaveToFile("jobs.json", static_cast<WorkingFamilyMember*>(f)->GetJobs());*/
			WorkingFamilyMember* ff = static_cast<WorkingFamilyMember*>(f);
			memberJson["type"] = 1;
			memberJson["totalSalary"] = ff->GetTotalSalary();
			memberJson["jobsIds"] = json::array();
			memberJson["jobsIds"] = ff->GetJobsIds();
			_jobReader->SaveToFile("jobs.json", ff->GetJobs());
			_purchaseReader->SaveToFile("purchases.json", f->GetPurchases());
		}
		else if (f->type = Child)
		{
			memberJson["type"] = 0;
		}
		memberJson["passwordHash"] = f->GetPasswordHash();
		memberJsonArray.push_back(memberJson);
	}

	if (fout.is_open())
	{
		string jsonToWrite;
		fout << memberJsonArray;
		fout.close();
	}
}
//string JsonFamilyFileReader::LoadFromFile(string path)
//{
//	ifstream fin;
//	fin.open(path, ios_base::in);
//	json data = json::parse(fin);
//	string result = data.dump();
//	return result;
//}