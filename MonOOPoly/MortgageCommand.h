#pragma once
#include "Command.h"
class MortgageCommand : public Command
{
	//Strategy or Visitor
	void mortgageProperty();
	void mortgageStation();
	void mortgageUtility();
public:
	MortgageCommand() = default;
	void execute() const override;
};

