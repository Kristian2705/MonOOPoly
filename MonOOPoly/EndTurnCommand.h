#pragma once
#include "Command.h"

class EndTurnCommand : public Command
{
public:
	EndTurnCommand() = default;
	void execute() const override;
};

