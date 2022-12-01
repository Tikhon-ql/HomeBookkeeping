#include "WorkingFamilyMember.h"

WorkingFamilyMember::WorkingFamilyMember(std::string name, std::string surname, float currentBalance) :FamilyMember(name, surname, currentBalance) { type = Adult; };

float WorkingFamilyMember::GetTotalSalary() { return _totalSalary; }

std::list<Job*> WorkingFamilyMember::GetJobs()const { return this->_jobs; }
std::list<int> WorkingFamilyMember::GetJobsIds()const { return this->jobsIds; }

void WorkingFamilyMember::AddJob(Job* job) { _jobs.push_back(job); jobsIds.push_back(job->GetId()); }