#include "ChildFamilyMember.h"

ChildFamilyMember::ChildFamilyMember(std::string username,std::string name, std::string surname, float currentBalance) :FamilyMember(username,name, surname, currentBalance) { type = Child; };

json ChildFamilyMember::GetDataJson()
{
	json result;
	result["type"] = 0;
	result["id"] = _id;
	result["username"] = _username;
	result["name"] = _name;
	result["surname"] = _surname;
	result["age"] = age;
	result["currentBalance"] = _currentBalance;
	result["password"] = _passwordHash;
	return result;
}

void ChildFamilyMember::SetDataJson(json json)
{
	_id = json["id"];
	_username = json["username"] ;
	_name = json["name"];
	_surname = json["surname"] ;
	age = json["age"];
	_currentBalance = json["currentBalance"];
	_passwordHash = json["password"];
}