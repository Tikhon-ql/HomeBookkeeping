#pragma once
#include <string>

class Person
{
protected:
	int _id = rand();
	std::string _name;
	std::string _surname;
	int age;
public:
	Person(std::string name, std::string suraname);
	int GetId()const;
	std::string GetName();
	std::string GetSurname();
  	virtual std::string ToString() = 0;
};