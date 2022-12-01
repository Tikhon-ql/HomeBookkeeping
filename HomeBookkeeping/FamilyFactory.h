#pragma once
#include "JobFactory.h"
#include "JobFileReader.h"
#include "FamilyMember.h"
#include "Factory.h"
#include <list>

class FamilyFactory : public Factory<FamilyMember*>
{
public:
	std::list<FamilyMember*> virtual Create(std::string data) = 0;
};