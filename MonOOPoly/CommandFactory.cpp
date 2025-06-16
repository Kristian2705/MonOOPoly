#include "CommandFactory.h"

Command* CommandFactory::readCommand(const MyString& commandType)
{
	if (commandType == "help") {
		return new HelpCommand();
	}
	if (commandType == "roll_dice") {
		return new RollDiceCommand();
	}
	return new InvalidCommand();
}
