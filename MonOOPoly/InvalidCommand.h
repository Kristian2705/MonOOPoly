#pragma once
#include "Command.h"

class InvalidCommand : public Command
{
public:
	InvalidCommand() = default;
	void execute() const override;
};

