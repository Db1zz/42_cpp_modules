#include "utils.hpp"
#include <iostream>
#include <ios>
#include <sstream>

bool utils::isFloat(const std::string &str) {
	float f;
  
	std::istringstream iss(str);
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail(); 
}

std::vector<std::string> utils::split(
	const std::string &str, const std::string &delim)
{
	std::vector<std::string> tokens;
	std::string token;
	size_t pos = 0, delim_pos = 0;
  
	while ((delim_pos = str.find(delim, pos)) != std::string::npos) {
	  token = std::string(str.begin() + pos, str.begin() + delim_pos);
		  tokens.push_back(token);
	  pos = delim_pos + delim.length();
	}
  
	tokens.push_back(std::string(str.begin() + pos, str.end()));
	return tokens;
  }