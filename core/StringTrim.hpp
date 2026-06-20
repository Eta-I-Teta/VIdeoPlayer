#pragma once
#include <string>


inline void trim(std::string& str) {
	size_t first = str.find_first_not_of(" \t\r\n");

	if (first == std::string::npos) 
	{
		str.clear();
		return;
	}

	size_t last = str.find_last_not_of(" \t\r\n");
	str = str.substr(first, last - first + 1);
}
