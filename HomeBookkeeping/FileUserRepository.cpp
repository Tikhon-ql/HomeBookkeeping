#include "FileUserRepository.h"
#include "ChildFamilyMember.h"
#include "WorkingFamilyMember.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

FileUserRepository::FileUserRepository(string path)
{
	_path = path;
	std::ifstream fin;
	fin.open(path, std::ios_base::in);
	if (fin.is_open())
	{
		json data = json::parse(fin);


		for (auto j : data)
		{

			User* user = nullptr;
			if (j["type"] == 0)
			{
				user = new ChildFamilyMember();
			}
			else if (j["type"] == 1)
			{
				user = new WorkingFamilyMember();
			}
			if (user)
			{
				user->SetDataJson(j);
				_users.push_back(user);
			}
		}
		fin.close();
	}
}

void FileUserRepository::Create(User* data)
{
	_users.push_back(data);
}
User* FileUserRepository::Read(string username)
{
	if (std::find_if(_users.begin(), _users.end(), [username](User*& user) { return user->GetUsername() == username; }) != _users.end())
	{
		User* user = *std::find_if(_users.begin(), _users.end(), [username](User*& user) { return user->GetUsername() == username; });
		return user;
	}
	return nullptr;
}
void FileUserRepository::Update(User* data)
{
	User* user = Read(data->GetUsername());
	user->SetId(data->GetId());
	user->SetUsername(data->GetUsername());
}
void FileUserRepository::Delete(int id)
{
	std::remove_if(_users.begin(), _users.end(), [id](User*& user) { return user->GetId() == id; });
}
list<User*> FileUserRepository::GetAll()
{
	return _users;
}
void FileUserRepository::SaveChanges()
{
	ofstream fout;
	fout.open(_path, ios_base::out);
	json usersJsonArray = json::array();
	for (auto u : _users)
	{
		usersJsonArray.push_back(u->GetDataJson());
	}
	if (fout.is_open())
	{
		fout << usersJsonArray;
		fout.close();
	}
}