#include "BankruptCommand.h"

void BankruptCommand::execute() const
{
	std::cout << "You are about to go bankrupt and lose the game!" << std::endl;
	std::cout << "Are you sure you want to do this? Type 'yes' or 'no'" << std::endl;
	MyString answer;
	std::cin >> answer;

	while (true) {
		if (answer == "no") {
			return;
		}
		if (answer == "yes") {
			std::cout << "Type your username to confirm: ";
			MyString username;
			std::cin >> username;
			if (username == game->getPlayerOnTurn().getName()) {
				game->endTurn();
				std::cout << "Good Game! You did well! Here are your stats:" << std::endl;
				//This has to use a different function which will be implemented later
				//game->getPlayerOnTurn().showInfo();
				return;
			}
			std::cout << "Sorry try again from the beginning! Please type 'yes' or 'no'." << std::endl;
			std::cin >> answer;
			continue;
		}
		std::cout << "Invalid input. Please type 'yes' or 'no'." << std::endl;
		std::cin >> answer;
	}
}
