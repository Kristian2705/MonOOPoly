#pragma once
#include "Command.h"
class UseReleaseCardCommand : public Command
{
public:
	UseReleaseCardCommand() = default;
	void execute() const override;
};

