#pragma once
#include "Command.h"
class PayForReleaseCommand : public Command
{
public:
	PayForReleaseCommand() = default;
	void execute() const override;
};

