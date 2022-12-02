#include "UserService.h"
#include <fstream>

int UserService::Logout(User* user)
{
	if (user->IsAuthenticated())
		user->SetAuthenticated(false);
	return user->GetId();
}

void UserService::Register(User* user, string password)
{
	if (user)
	{
		user->SetPassword(password);
		_repository->Create(user);
		_repository->SaveChanges();
	}
	else
	{
		throw exception("User is already authenticated!");
	}
}


User* UserService::Authenticate(string username, string passwordHash)
{
	User* user = _repository->Read(username);
	if (user && !user->IsAuthenticated())
	{
		if (user->CompareTo(username, passwordHash))
		{
			user->SetAuthenticated(true);
			return user;
		}
		else
		{
			//throw exception("User hadn't been found!!!");
			return nullptr;
		}
	}
	else 
	{
		//throw exception("User hadn't been found!!!");
		return nullptr;
	}
}
