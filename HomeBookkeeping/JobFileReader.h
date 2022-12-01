#pragma once
#include "FileReader.h"
#include "Job.h"
#include <string>
#include <list>

class JobFileReader : FileReader<std::list<Job*>>
{
public:
	std::string virtual LoadFromFile(std::string path) { return FileReader<std::list<Job*>>::LoadFromFile(path); };
	void virtual SaveToFile(std::string path, std::list<Job*> jobs) = 0;
};