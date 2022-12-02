#pragma once
#include "User.h"
#include "UserRepository.h"

class UserService
{
private:
	UserRepository* _repository;
public:
	UserService(UserRepository* repository) :_repository(repository) {};
	int Authenticate(string username, string passwordHash);
	int Logout(User* user);
	void Register(User* user, string password);
};

