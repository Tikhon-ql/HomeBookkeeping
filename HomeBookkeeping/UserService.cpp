#include "UserService.h"
#include <fstream>

int UserService::Logout(User* user)
{
	if (user->IsAuthenticated())
		user->isAuthenticate = false;
}

void UserService::Register(User* user, string password)
{
	if (user)
	{
		user->_passwordHash = password;
		_repository->Create(user);
		_repository->SaveChanges();
	}
	else
	{
		throw exception("User is already authenticated!");
	}
}


int UserService::Authenticate(string username, string passwordHash)
{
	User* user = _repository->Read(username);
	if (!user->isAuthenticate)
	{
		if (user->CompareTo(username, passwordHash))
		{
			user->isAuthenticate = true;
			return user->_id;
		}
		else
		{
			throw exception("User hadn't been found!!!");
			return -1;
		}
	}
}
