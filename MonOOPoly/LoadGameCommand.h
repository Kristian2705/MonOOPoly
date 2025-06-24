#pragma once
#include "Command.h"
class LoadGameCommand : public Command
{
public:
	LoadGameCommand() = default;
	void execute() const override;
};

