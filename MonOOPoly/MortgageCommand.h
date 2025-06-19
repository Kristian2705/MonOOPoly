#pragma once
#include "Command.h"
class MortgageCommand : public Command
{
	//Strategy or Visitor
	void mortgageProperty() const;
	void mortgageStation() const;
	void mortgageUtility() const;
public:
	MortgageCommand() = default;
	void execute() const override;
};

