#pragma once
#include "Command.h"
class SeeMapCommand : public Command
{
public:
	SeeMapCommand() = default;
	void execute() const override;
};

