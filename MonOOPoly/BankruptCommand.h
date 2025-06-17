#pragma once
#include "Command.h"

class BankruptCommand : public Command {
public:
	BankruptCommand() = default;
	void execute() const override;
};