#include "JsonPurchaseFactory.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

list<Purchase*> JsonPurchaseFactory::Create(string data)
{
	json json = json::parse(data);
	list<Purchase*> result;
	for (auto j : json)
	{
		Purchase* newPurchase = new Purchase(j["name"],j["memberId"],j["cost"],j["dateTime"]);
		result.push_back(newPurchase);
	}
	return result;
}