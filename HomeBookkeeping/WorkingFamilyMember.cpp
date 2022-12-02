#include "WorkingFamilyMember.h"

WorkingFamilyMember::WorkingFamilyMember(std::string username, std::string name, std::string surname, float currentBalance) :FamilyMember(username, name, surname, currentBalance) { type = Adult; };

float WorkingFamilyMember::GetTotalSalary() { return _totalSalary; }

std::list<Job*> WorkingFamilyMember::GetJobs()const { return this->_jobs; }
std::list<int> WorkingFamilyMember::GetJobsIds()const { return this->jobsIds; }

void WorkingFamilyMember::AddJob(Job* job) { _jobs.push_back(job); jobsIds.push_back(job->GetId()); }

json WorkingFamilyMember::GetDataJson()
{
	json result;
	result["type"] = 1;
	result["id"] = _id;
	result["username"] = _username;
	result["name"] = _name;
	result["surname"] = _surname;
	result["age"] = age;
	result["currentBalance"] = _currentBalance;
	result["totalSalary"] = _totalSalary;
	result["password"] = _passwordHash;
	return result;
}

void WorkingFamilyMember::SetDataJson(json json)
{
	_id = json["id"];
	_username = json["username"];
	_name = json["name"];
	_surname = json["surname"];
	age = json["age"];
	_currentBalance = json["currentBalance"];
	_totalSalary = json["totalSalary"];
	_passwordHash = json["password"];
}