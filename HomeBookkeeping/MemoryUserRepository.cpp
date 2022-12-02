#include "MemoryUserRepository.h"

void MemoryUserRepository::Create(User* user)
{
	_users.push_back(user);
}

User* MemoryUserRepository::Read(string username)
{
	return *std::find_if(_users.begin(), _users.end(), [](const User& user, string username) { return user.GetUsername() == username; });
}

void MemoryUserRepository::Update(User* data)
{
	User* user = Read(data->GetUsername());
	user->SetId(data->GetId());
	user->SetUsername(data->GetUsername());
}

void MemoryUserRepository::Delete(int id)
{
	 std::remove_if(_users.begin(), _users.end(), [](const User& user, int id) { return user.GetId() == id; });
}

list<User*> MemoryUserRepository::GetAll()
{
	return _users;
}

void MemoryUserRepository::SaveChanges() {};