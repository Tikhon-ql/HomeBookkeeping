#include "JsonJobFactory.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

list<Job*> JsonJobFactory::Create(string data)
{
	json json = json::parse(data);
	list<Job*> result;
	for (auto j : json)
	{
		Job* newJob = new Job(j["organization"],j["specialization"],j["salary"]);
		newJob->SetId(j["id"]);
		result.push_back(newJob);
	}
	return result;
}