#pragma once
#include "JobFactory.h"
#include "JobFileReader.h"
#include "Purchase.h"
#include "Factory.h"
#include <list>

class PurchaseFactory : public Factory<Purchase*>
{
public:
	std::list<Purchase*> virtual Create(std::string data) = 0;
};