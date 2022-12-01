#pragma once
#include <list>
#include <string>

template<class T>
class Factory
{
public:
	std::list<T> virtual Create(std::string data) = 0;
};