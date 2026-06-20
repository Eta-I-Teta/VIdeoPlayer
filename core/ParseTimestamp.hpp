#pragma once
#include <string>
#include <stdexcept>
#include <cstdio>

double parse_timestamp(const std::string& timestamp) {
	int hours = 0, minutes = 0, seconds = 0, milliseconds = 0;
	
	int parsed = std::sscanf(
		timestamp.c_str(), 
		"%d:%d:%d,%d", 
		&hours, &minutes, &seconds, &milliseconds
	);
	
	if (parsed != 4) {
		throw std::invalid_argument("parseTimestamp::Некорректный формат времени: " + timestamp);
	}
	
	return hours * 3600.0 + minutes * 60.0 + seconds + milliseconds / 1000.0;
}
