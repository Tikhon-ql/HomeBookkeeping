#pragma once
#include <list>
#include <string>
using namespace std;

template<typename T>
class Repository
{
public:
	virtual void Create(T data) = 0;
	virtual T Read(std::string username) = 0;
	virtual void Update(T data) = 0;
	virtual void Delete(int id) = 0;

	virtual list<T> GetAll() = 0;

	virtual void SaveChanges() = 0;
};

