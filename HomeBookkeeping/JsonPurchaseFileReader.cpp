#include "JsonPurchaseFileReader.h"

#include <string>
#include <list>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

void JsonPurchaseFileReader::SaveToFile(string path, list<Purchase*> purchases)
{
	ofstream fout;
	fout.open(path, ios_base::out);
	json purchaseJsonArray = json::array();
	json purchaseJson;
	for (auto f : purchases)
	{
		purchaseJson["name"] = f->GetItemName();
		purchaseJson["memberId"] = f->GetFamilyMemberId();
		purchaseJson["cost"] = f->GetCost();
		purchaseJson["dateTime"] = f->GetDateTime();
		purchaseJsonArray.push_back(purchaseJson);
	}

	if (fout.is_open())
	{
		string jsonToWrite;
		fout << purchaseJsonArray;
		fout.close();
	}
}
