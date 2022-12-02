#include "User.h"


string User::GetUsername()const { return _username; }
string User::SetUsername(string username) { _username = username; return _username; }

string User::EditPassword(string passwordHash, string token)
{
	_passwordHash = passwordHash;
	return _passwordHash;
}

string User::SetPassword(string passwordHash) { _passwordHash = passwordHash; return _passwordHash; }
string User::GetPasswordHash()const { return _passwordHash; }

bool User::CompareTo(User* user) 
{
	if (_passwordHash == user->_passwordHash)
		return true;
	return false;
}

bool User::CompareTo(string name, string password)
{
	if (name == _username && _passwordHash == password)
		return true;
	return false;
}

int User::GetId()const { return _id; }
int User::SetId(int id) { _id = id; return _id; }

bool User::IsAuthenticated()const { return isAuthenticate; }

void User::SetAuthenticated(bool value) { isAuthenticate = value; }
