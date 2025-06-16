#include "CommandFactory.h"

Command* CommandFactory::readCommand(const MyString& commandType)
{
	if (commandType == "help") {
		return new HelpCommand();
	}
}
