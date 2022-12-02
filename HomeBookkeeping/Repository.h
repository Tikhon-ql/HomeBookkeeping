#pragma once
#include <list>
#include <string>
using namespace std;

template<typename T>
class Repository
{
public:
	void virtual Create(T data) = 0;
	virtual T Read(std::string username) = 0;
	void virtual Update(T data) = 0;
	void virtual Delete(int id) = 0;

	list<T> virtual GetAll() = 0;

	void virtual SaveChanges() = 0;
};

