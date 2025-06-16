#pragma once
#include "Command.h"

class SeeInfoCommand : public Command
{
public:
	SeeInfoCommand() = default;
	void execute() const override;
};

