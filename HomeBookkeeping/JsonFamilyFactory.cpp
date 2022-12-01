#include "JsonFamilyFactory.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

list<FamilyMember*> JsonFamilyFactory::Create(string data)
{
	json json = json::parse(data);
	list<FamilyMember*> result;
	for (auto j : json)
	{
		if (j["type"] == 0)
		{
			//TODO::Create child member;
		}
		else if (j["type"] == 1)
		{
			//TODO::Create working member;
		}
		/*FamilyMember newMember = FamilyMember(j["name"],j["surname"],j["currentBalance"]);
		result.push_back(newMember);*/
	}
	return result;
}