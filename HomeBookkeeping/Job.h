#pragma once
#include <string>

class Job
{
private:
	int _id;
	std::string _organization;
	std::string _specialization;
	double _salary;
public:
	Job(std::string organization, std::string specialization, double salary);
	int GetId() const;
	void SetId(int id);
	std::string GetOrganization() const;
	std::string GetSpecialization() const;
	double GetSalary()const;
};

