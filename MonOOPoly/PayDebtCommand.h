#pragma once
#include "Command.h"
class PayDebtCommand : public Command
{
public:
	PayDebtCommand() = default;
	void execute() const override;
};

