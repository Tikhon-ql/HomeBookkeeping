#include "Person.h"
#include <string>

Person::Person(std::string name, std::string surname)
{
	_name = name;
	_surname = surname;
}

int Person::GetId()const { return _id; }
std::string Person::GetName() { return _name; }
std::string Person::GetSurname() { return _surname; }