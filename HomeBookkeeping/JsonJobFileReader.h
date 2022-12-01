#pragma once
#include "JobFileReader.h"

class JsonJobFileReader : public JobFileReader
{
public:
	//std::string LoadFromFile(std::string path);
	void SaveToFile(std::string path, std::list<Job*> jobs);
};

