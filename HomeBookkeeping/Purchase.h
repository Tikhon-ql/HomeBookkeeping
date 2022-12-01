#pragma once
#include<string>

class Purchase
{
private:
	int _id;
	std::string _itemName;
	int _familyMemberId;
	float _cost;
	int _dateTime;
public:
	Purchase(std::string itemName, int familyMemberId, float cost, int dateTime);
	std::string GetItemName()const;
	int GetFamilyMemberId()const;
	float GetCost()const;
	int GetDateTime()const;
};


