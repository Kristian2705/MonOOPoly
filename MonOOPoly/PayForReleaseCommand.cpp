#include "PayForReleaseCommand.h"

void PayForReleaseCommand::execute() const
{
	int getPlayersInGameCount = game->getPlayersInGameCount();
	if (getPlayersInGameCount == 0) {
		throw std::invalid_argument("No game in progress. Please start a new game.");
	}

	Player& player = game->getPlayerOnTurn();
	if (!player.isInJail()) {
		throw std::invalid_argument("You are not in jail and you don't have to pay, so chill ;)");
	}
	if(player.getMoney() < GameConstants::JAIL_RELEASE_PRICE) {
		throw std::invalid_argument("You don't have enough money to pay for release!");
	}
	player.addMoney(-GameConstants::JAIL_RELEASE_PRICE);
	player.setJailStatus();
	if (game->getRolledStatus()) {
		std::cout << std::endl;
		std::cout << "You are free. You'll will be able to roll next turn." << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << std::endl;
		std::cout << "You are free. You can now roll the dice!" << std::endl;
		std::cout << std::endl;
	}
}
