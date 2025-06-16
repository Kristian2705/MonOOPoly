#include "RollDiceCommand.h"

void RollDiceCommand::execute() const
{
	if (game->getRolledStatus() && !game->getPairStatus()) {
		throw std::invalid_argument("You have already rolled and didn't get a pair.");
	}
	Player& playerOnTurn = game->getPlayerOnTurn();
	std::cout << "Press Enter to roll..." << std::endl;
	std::cin.get();
	int total = game->rollDice();
	if (playerOnTurn.isInJail()) {
		if (game->getPairStatus()) {
			playerOnTurn.setJailStatus();
			game->setPairStatus();
			playerOnTurn.moveTo(playerOnTurn.getCurrentPosition() + total);
		}
		return;
	}
	playerOnTurn.moveTo(playerOnTurn.getCurrentPosition() + total);
	game->applyFieldEffect(playerOnTurn.getCurrentPosition());
}
