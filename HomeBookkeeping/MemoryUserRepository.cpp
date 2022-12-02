#include "MemoryUserRepository.h"

void MemoryUserRepository::Create(User* user)
{
	_users.push_back(user);
}

User* MemoryUserRepository::Read(string username)
{
	User* user = *std::find_if(_users.begin(), _users.end(), [username](User*& user) { return user->GetUsername() == username; });
	return user;
}

void MemoryUserRepository::Update(User* data)
{
	User* user = Read(data->GetUsername());
	user->SetId(data->GetId());
	user->SetUsername(data->GetUsername());
}

void MemoryUserRepository::Delete(int id)
{
	 std::remove_if(_users.begin(), _users.end(), [id](User*& user) { return user->GetId() == id; });
}

list<User*> MemoryUserRepository::GetAll()
{
	return _users;
}

void MemoryUserRepository::SaveChanges() {};