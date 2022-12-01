#pragma once
#include "Person.h"
#include<list>
#include<string>
#include "Purchase.h"
#include "FamilyMemberType.h"

class FamilyMember : public Person
{
private:
	float _currentBalance;
	std::list<Purchase*> _purchase;
public:
	FamilyMemberType type;
	FamilyMember(std::string name, std::string surname, float currentBalance);
	std::string ToString();

	float GetCurrentBalance()const;
	std::list<Purchase*> GetPurchases()const;
	void AddPurchase(Purchase* purchase);
};