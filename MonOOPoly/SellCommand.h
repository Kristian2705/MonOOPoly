#pragma once
#include "Command.h"
class SellCommand : public Command
{
public:
	SellCommand() = default;
	void execute() const override;
};

