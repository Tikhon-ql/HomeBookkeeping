#include "ChildFamilyMember.h"

ChildFamilyMember::ChildFamilyMember(std::string username,std::string name, std::string surname, float currentBalance) :FamilyMember(username,name, surname, currentBalance) { type = Child; };
