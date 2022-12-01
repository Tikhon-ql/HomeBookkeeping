#pragma once
#include "FamilyFactory.h"
#include <list>

class JsonFamilyFactory : public FamilyFactory
{
	std::list<FamilyMember*> Create(std::string data);
};