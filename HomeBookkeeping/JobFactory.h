#pragma once
#include "FamilyMember.h"
#include "Job.h"
#include "Factory.h"
#include <list>

class JobFactory : public Factory<Job*>
{
public:
	std::list<Job*> virtual Create(std::string data) = 0;
};