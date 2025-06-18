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
			std::cout << "Type your id to confirm: ";
			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (!str.hasLettersOnly()) {
				int id = str.stoi();
				if (id == game->getPlayerOnTurn().getId()) {
					game->endTurn();
					std::cout << "Good Game! You did well! Here are your stats:" << std::endl;
					//This has to use a different function which will be implemented later
					//game->getPlayerOnTurn().showInfo();
					return;
				}
			}
			std::cout << "Sorry try again from the beginning! Please type 'yes' to continue or 'no' to go back." << std::endl;
			std::cin >> answer;
			continue;
		}
		std::cout << "Invalid input. Please type 'yes' or 'no'." << std::endl;
		std::cin >> answer;
	}
}
