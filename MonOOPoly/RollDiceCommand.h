#pragma once
#include "Command.h"
class RollDiceCommand : public Command
{
public:
	RollDiceCommand() = default;
	void execute() const override;
};

