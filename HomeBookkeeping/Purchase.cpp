#include "Purchase.h"
#include <string>

Purchase::Purchase(std::string itemName, int familyMemberId, float cost, int dateTime)
{
	_itemName = itemName;
	_familyMemberId = familyMemberId;
	_cost = cost;
	_dateTime = dateTime;
}

std::string Purchase::GetItemName()const { return _itemName; }
int Purchase::GetFamilyMemberId ()const { return _familyMemberId; }
float Purchase::GetCost ()const { return _cost; }
int Purchase::GetDateTime()const { return _dateTime; }