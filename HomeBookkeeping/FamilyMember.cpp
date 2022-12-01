#include "FamilyMember.h"

FamilyMember::FamilyMember(std::string name, std::string surname, float currentBalance) :Person(name, surname) { _currentBalance = currentBalance; }

std::string FamilyMember::ToString() { return _name + " " + _surname; }
float FamilyMember::GetCurrentBalance()const { return _currentBalance; }
std::list<Purchase*> FamilyMember::GetPurchases()const { return _purchase; }
void FamilyMember::AddPurchase(Purchase* purchase) { _purchase.push_back(purchase); }