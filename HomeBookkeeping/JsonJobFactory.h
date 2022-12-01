#pragma once
#include "JobFactory.h"
#include <list>

class JsonJobFactory : public JobFactory
{
	std::list<Job*> Create(std::string data);
};