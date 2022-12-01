#include "ChildFamilyMember.h"

ChildFamilyMember::ChildFamilyMember(std::string name, std::string surname, float currentBalance) :FamilyMember(name, surname, currentBalance) { type = Child; };
