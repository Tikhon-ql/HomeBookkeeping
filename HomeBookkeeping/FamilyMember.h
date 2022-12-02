#pragma once
#include "User.h"
#include<list>
#include<string>
#include "Purchase.h"
#include "FamilyMemberType.h"

using namespace std;

class FamilyMember : public User
{
private:
	string _name;
	string _surname;
	int age;
	float _currentBalance;
	std::list<Purchase*> _purchase;
public:
	FamilyMemberType type;
	FamilyMember(string username, string name, string surname, float currentBalance);
	virtual std::string ToString();

	string GetName()const;
	string SetName(string name);

	string GetSurname()const;
	string SetSurname(string surname);

	float GetCurrentBalance()const;
	std::list<Purchase*> GetPurchases()const;
	void AddPurchase(Purchase* purchase);
};