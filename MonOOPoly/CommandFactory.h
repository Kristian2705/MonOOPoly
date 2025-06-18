#pragma once
#include "Command.h"
#include "HelpCommand.h"
#include "RollDiceCommand.h"
#include "InvalidCommand.h"
#include "SeeInfoCommand.h"
#include "EndTurnCommand.h"
#include "PayForReleaseCommand.h"
#include "BankruptCommand.h"
#include "BuildCommand.h"
#include "SellCommand.h"

class CommandFactory
{
public:
	static Command* readCommand(const MyString& commandType);
	virtual ~CommandFactory() = default;
};

