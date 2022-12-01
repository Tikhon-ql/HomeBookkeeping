#pragma once
#include <string>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

template<class T>
class FileReader
{
public:
	std::string virtual LoadFromFile(std::string path) {
		std::ifstream fin;
		fin.open(path, std::ios_base::in);
		json data = json::parse(fin);
		std::string result = data.dump();
		return result;
	}
	void virtual SaveToFile(std::string path, T data) = 0;
};

