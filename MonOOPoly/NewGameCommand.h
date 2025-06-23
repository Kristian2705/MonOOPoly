#pragma once
#include "Command.h"
class NewGameCommand : public Command
{
public:
	NewGameCommand() = default;
	void execute() const override;
};

