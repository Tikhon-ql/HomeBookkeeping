#include "JsonJobFileReader.h"
#include <string>
#include <list>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

void JsonJobFileReader::SaveToFile(string path, list<Job*> jobs)
{
	ofstream fout;
	fout.open(path, ios_base::out);
	json jobJsonArray = json::array();
	json jobJson;
	for (auto j : jobs)
	{
		jobJson["id"] = j->GetId();
		jobJson["organization"] = j->GetOrganization();
		jobJson["specialization"] = j->GetSpecialization();
		jobJson["salary"] = j->GetSalary();
		jobJsonArray.push_back(jobJson);
	}

	if (fout.is_open())
	{
		string jsonToWrite;
		fout << jobJsonArray;
		fout.close();
	}
}
//string JsonJobFileReader::LoadFromFile(string path)
//{
//	ifstream fin;
//	fin.open(path, ios_base::in);
//	json data = json::parse(fin);
//	string result = data.dump();
//	return result;
//}