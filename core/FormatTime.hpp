#pragma once
#include <string>
//#include <cstdio>


std::string format_time(double seconds) {
	int totalSeconds = static_cast<int>(seconds);
	int hours = totalSeconds / 3600;
	int minutes = (totalSeconds % 3600) / 60;
	int secs = totalSeconds % 60;

	char buffer[32];
	if (hours > 0) {
		std::snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hours, minutes, secs);
	}
	else {
		std::snprintf(buffer, sizeof(buffer), "%02d:%02d", minutes, secs);
	}
	return std::string(buffer);
}
