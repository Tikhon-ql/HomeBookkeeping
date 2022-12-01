#include "Job.h"
#include <string>

Job::Job(std::string organization, std::string specialization, double salary)
{
	_organization = organization;
	_specialization = specialization;
	_salary = salary;
}

int Job::GetId()const { return _id; }
std::string Job::GetOrganization()const { return _organization; }
std::string Job::GetSpecialization()const { return _specialization; }
void Job::SetId(int id) { _id = id; }
double Job::GetSalary()const { return _salary; }