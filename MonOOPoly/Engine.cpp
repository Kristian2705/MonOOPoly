#include "Engine.h"

void Engine::run()
{
	Monopoly* game = Monopoly::getInstance();

	game->showMainMenu();

	while (true) {
		MyString commandName;
		std::cout << "> ";
		std::cin >> commandName;

		if (commandName == "exit") {
			game->truncateBinaryFiles();
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
