#pragma once
#include "User.h"
#include "Repository.h"

using namespace std;

class UserRepository : public Repository<User*>
{
public:
	void virtual  Create(User* data) = 0;
	virtual User* Read(string username) = 0;
	void virtual Update(User* data) = 0;
	void virtual  Delete(int id) = 0;
	list<User*> virtual GetAll() = 0;
	void virtual SaveChanges() = 0;
};

