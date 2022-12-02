#pragma once
#include "FamilyMember.h"
#include "Job.h"
#include <list>
#include <string>


class WorkingFamilyMember : public FamilyMember
{
private:
	std::list<Job* > _jobs;
	std::list<int> jobsIds;
	float _totalSalary;
public:
	WorkingFamilyMember() { type = Adult; }
	WorkingFamilyMember(std::string username,std::string name,std::string surname, float currentBalance);
	void AddJob(Job* job);
	std::list<Job*> GetJobs()const;
	std::list<int> GetJobsIds()const;
	float GetTotalSalary();

	json GetDataJson();
	void SetDataJson(json json);
};

