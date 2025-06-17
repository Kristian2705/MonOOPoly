#include "EndTurnCommand.h"

void EndTurnCommand::execute() const
{
	if (game->getPairStatus()) {
		std::cout << "You have thrown a pair. Please roll again and then end your turn!" << std::endl;
		return;
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
