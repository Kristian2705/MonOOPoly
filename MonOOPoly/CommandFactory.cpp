#include "CommandFactory.h"

Command* CommandFactory::readCommand(const MyString& commandType)
{
	if (commandType == "help") {
		return new HelpCommand();
	}
	if (commandType == "roll_dice") {
		return new RollDiceCommand();
	}
	if (commandType == "see_info") {
		return new SeeInfoCommand();
	}
	if (commandType == "end_turn") {
		return new EndTurnCommand();
	}
	return new InvalidCommand();
}
