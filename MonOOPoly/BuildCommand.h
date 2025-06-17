#pragma once
#include "Command.h"

class BuildCommand : public Command
{
public:
	BuildCommand() = default;
	void execute() const override;
};

