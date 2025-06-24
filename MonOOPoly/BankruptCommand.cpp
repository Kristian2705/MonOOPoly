#include "BankruptCommand.h"

void BankruptCommand::execute() const
{
	int getPlayersInGameCount = game->getPlayersInGameCount();

	if (getPlayersInGameCount == 0) {
		throw std::invalid_argument("No game in progress. Please start a new game.");
	}

	std::cout << "You are about to go bankrupt and lose the game!" << std::endl;
	std::cout << "Are you sure you want to do this? Type 'yes' or 'no'" << std::endl;

	MyString answer;
	std::cin >> answer;

	while (true) {
		if (answer == "no") {
			return;
		}
		if (answer == "yes") {
			Player& playerOnTurn = game->getPlayerOnTurn();

			std::cout << "Type your id to confirm: ";
			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;

			MyString str(buffer);

			if (str.isValidNumber()) {

				int id = str.stoi();

				if (id == playerOnTurn.getId()) {

					std::cout << "----------------------------" << std::endl;
					std::cout << "You have successfully gone bankrupt! You are out of the game!" << std::endl;
					std::cout << "Good Game! You did well!" << std::endl;
					std::cout << "----------------------------" << std::endl;

					playerOnTurn.resign();

					if (game->checkGameOver()) {

						std::cout << "------------------------------" << std::endl;
						std::cout << "Game Over! Thanks for playing!" << std::endl;
						std::cout << "------------------------------" << std::endl;
						std::cout << std::endl;
						std::cout << "The winner is: " << std::endl;

						game->getWinner()->showInfo();
						std::cout << std::endl;

						std::cout << "Press enter to exit the game..." << std::endl;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin.get();

						game->truncateBinaryFiles();

						throw std::overflow_error("You are always welcome to play again!");
					}

					game->endTurn();

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
