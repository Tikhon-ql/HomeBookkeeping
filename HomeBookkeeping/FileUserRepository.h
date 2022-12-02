#pragma once
#include "UserRepository.h"

class FileUserRepository : public UserRepository
{
private:
	list<User*> _users;
	string _path;
public:
	FileUserRepository(string path);
	void Create(User* data);
	User* Read(string username);
	void Update(User* data);
	void Delete(int id);
	list<User*> GetAll();
	void SaveChanges();
};

