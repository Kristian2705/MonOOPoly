#pragma once
#include "Command.h"
#include "HelpCommand.h"
#include "RollDiceCommand.h"
#include "InvalidCommand.h"

class CommandFactory
{
public:
	static Command* readCommand(const MyString& commandType);
	virtual ~CommandFactory() = default;
};

