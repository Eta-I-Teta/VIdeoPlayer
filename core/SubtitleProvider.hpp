#pragma once
#include <iostream>
#include <memory>
#include <string>

class SubtitleProvider {
public:
	virtual ~SubtitleProvider() = default;

	virtual bool load(std::unique_ptr<std::istream> stream) = 0;

	virtual std::string get_line(double timeSec) const = 0;
};
