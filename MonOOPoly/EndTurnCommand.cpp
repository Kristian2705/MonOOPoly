#include "EndTurnCommand.h"

void EndTurnCommand::execute() const
{
	if (!game->getRolledStatus()) {
		throw std::invalid_argument("Roll the dice first!");
	}

	const Player& playerOnTurn = game->getPlayerOnTurn();

	if(playerOnTurn.isInDebt()) {
		throw std::invalid_argument("You are in debt and can't end your turn! Find money or go bankrupt!");
	}

	if (game->getPairStatus()) {
		throw std::invalid_argument("You have thrown a pair. Please roll again and then end your turn!");
	}

	std::cout << "Are you sure you want to end your turn? Type 'yes' or 'no'" << std::endl;
	MyString answer;
	std::cin >> answer;

	while (true) {
		if (answer == "no") {
			return;
		}
		if (answer == "yes") {
			game->endTurn();
			return;
		}
		std::cout << "Invalid input. Please type 'yes' or 'no'." << std::endl;
		std::cin >> answer;
	}
}
