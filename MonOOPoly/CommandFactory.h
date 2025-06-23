#pragma once
#include "Command.h"
#include "NewGameCommand.h"
#include "HelpCommand.h"
#include "RollDiceCommand.h"
#include "InvalidCommand.h"
#include "SeeInfoCommand.h"
#include "EndTurnCommand.h"
#include "PayForReleaseCommand.h"
#include "BankruptCommand.h"
#include "BuildCommand.h"
#include "SellCommand.h"
#include "MortgageCommand.h"
#include "UseReleaseCardCommand.h"
#include "TradeCommand.h"
#include "PayDebtCommand.h"

class CommandFactory
{
public:
	static Command* readCommand(const MyString& commandType);
	virtual ~CommandFactory() = default;
};

