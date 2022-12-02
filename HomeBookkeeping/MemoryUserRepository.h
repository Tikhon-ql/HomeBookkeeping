#pragma once
#include "UserRepository.h"

class MemoryUserRepository : public UserRepository
{
private:
	list<User*> _users;
public:
	MemoryUserRepository(list<User*> users) :_users(users) {};
	void Create(User* data);
	User* Read(string username);
	void Update(User* data);
	void Delete(int id);
	list<User*> GetAll();
	void SaveChanges();
};

