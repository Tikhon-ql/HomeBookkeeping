#pragma once
#include "User.h"
#include "Repository.h"

using namespace std;

class UserRepository : public Repository<User*>
{
public:
	virtual void Create(User* data) = 0;
	virtual User* Read(string username) = 0;
	virtual void Update(User* data) = 0;
	void virtual  Delete(int id) = 0;
	list<User*> virtual GetAll() = 0;
	void virtual  SaveChanges() = 0;
};

