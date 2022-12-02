#pragma once
#include<string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

class User
{
protected:
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

	json virtual GetDataJson() = 0;

	void virtual SetDataJson(json json) = 0;

	//virtual string ToString()const = 0;
};

