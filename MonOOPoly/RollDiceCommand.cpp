#include "RollDiceCommand.h"

void RollDiceCommand::execute() const
{
	int getPlayersInGameCount = game->getPlayersInGameCount();
	if (getPlayersInGameCount == 0) {
		throw std::invalid_argument("No game in progress. Please start a new game.");
	}

	if (game->getRolledStatus() && !game->getPairStatus()) {
		throw std::invalid_argument("You have already rolled and didn't get a pair.");
	}

	Player& playerOnTurn = game->getPlayerOnTurn();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Press Enter to roll..." << std::endl;
	std::cin.get();

	int total = game->rollDice();

	if (playerOnTurn.isInJail()) {
		if (game->getPairStatus()) {
			playerOnTurn.setJailStatus();
			game->resetPairStatus();
			playerOnTurn.moveTo(playerOnTurn.getCurrentPosition() + total);
		}
		else {
			playerOnTurn.decreaseTimesLeft();
			std::cout << "Try next turn (rolls left: " << playerOnTurn.getTimesLeft() << ") or pay $50." << std::endl;
			if (playerOnTurn.getTimesLeft() == 0) {
				playerOnTurn.setJailStatus();
			}
		}
		return;
	}
	playerOnTurn.moveTo(playerOnTurn.getCurrentPosition() + total);
}
