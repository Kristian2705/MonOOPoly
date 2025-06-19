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
	if (commandType == "pay_release") {
		return new PayForReleaseCommand();
	}
	if (commandType == "bankrupt") {
		return new BankruptCommand();
	}
	if (commandType == "build") {
		return new BuildCommand();
	}
	if (commandType == "sell") {
		return new SellCommand();
	}
	if (commandType == "mortgage") {
		return new MortgageCommand();
	}
	if (commandType == "use_card") {
		return new UseReleaseCardCommand();
	}
	if (commandType == "trade") {
		return new TradeCommand();
	}
	return new InvalidCommand();
}
