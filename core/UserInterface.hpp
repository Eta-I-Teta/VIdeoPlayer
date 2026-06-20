#pragma once
#include "PlayerCommand.hpp"

class UserInterface {
public:
	virtual ~UserInterface() = default;

	virtual PlayerCommand get_command() = 0;
};
