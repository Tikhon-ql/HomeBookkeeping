#pragma once
#include "FamilyMember.h"
#include <string>
class ChildFamilyMember :public FamilyMember
{
public:
	ChildFamilyMember(std::string username,std::string name, std::string surname, float currentBalance);
};

