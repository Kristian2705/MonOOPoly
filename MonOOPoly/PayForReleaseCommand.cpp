#include "PayForReleaseCommand.h"

void PayForReleaseCommand::execute() const
{
	Player& player = game->getPlayerOnTurn();
	if (!player.isInJail()) {
		throw std::invalid_argument("You are not in jail and you don't have to pay, so chill ;)");
	}
	player.addMoney(-GameConstants::JAIL_RELEASE_PRICE);
	player.setJailStatus();
	if (game->getRolledStatus()) {
		std::cout << "You are free. You'll will be able to roll next turn." << std::endl;
	}
	else {
		std::cout << "You are free. You can now roll the dice!" << std::endl;
	}
}
