#include "Engine.h"

void Engine::run()
{
	//This will be for the new game command
	Monopoly* game = Monopoly::getInstance();
	//game->welcomePlayers();

	while (true) {
		MyString commandName;
		std::cout << "> ";
		std::cin >> commandName;

		if (commandName == "exit") {
			break;
		}
		try {
			Command* command = CommandFactory::readCommand(commandName);
			command->execute();
			delete command;
		}
		catch (const std::overflow_error& e) {
			std::cerr << e.what() << std::endl;
			break;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	game->freeInstance();
}
