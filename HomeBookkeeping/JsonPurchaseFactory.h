#pragma once
#include "PurchaseFactory.h"
#include <list>

class JsonPurchaseFactory : public PurchaseFactory
{
	std::list<Purchase*> Create(std::string data);
};