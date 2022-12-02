#pragma once
#include "UserService.h"
#include<string>

using namespace std;

class User
{
protected:
	friend UserService;
	int _id = rand();
	string _username;
	string _passwordHash;
	string _token = "";

	bool isAuthenticate = false;
public:
	User() {};
	User(string username) :_username(username) {};

	int GetId()const;
	int SetId(int id);

	string GetUsername()const;
	string SetUsername(string username);

	string SetPassword(string passwordHash);
	string GetPasswordHash()const;

	string EditPassword(string passwordHash, string token);

	bool CompareTo(User* user);

	bool CompareTo(string name, string password);

	bool IsAuthenticated()const;

	void SetAuthenticated(bool value);
};

