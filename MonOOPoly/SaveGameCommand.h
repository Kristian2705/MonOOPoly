#pragma once
#include "Command.h"
class SaveGameCommand : public Command
{
public:
	SaveGameCommand() = default;
	void execute() const override;
};

