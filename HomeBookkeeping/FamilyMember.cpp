#include "FamilyMember.h"

FamilyMember::FamilyMember(string username,string name, string surname, float currentBalance):User(username), _name(name), _surname(surname), _currentBalance(currentBalance) {};

std::string FamilyMember::ToString() { return _name + " " + _surname; }

float FamilyMember::GetCurrentBalance()const { return _currentBalance; }

std::list<Purchase*> FamilyMember::GetPurchases()const { return _purchase; }

void FamilyMember::AddPurchase(Purchase* purchase) { _purchase.push_back(purchase); }

string FamilyMember::GetName()const { return _name; }
string FamilyMember::SetName(string name) { _name = name; return _name; }

string FamilyMember::GetSurname()const { return _surname; }
string FamilyMember::SetSurname(string surname) { _surname = surname; return _surname; }
