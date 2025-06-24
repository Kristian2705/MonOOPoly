#include "UseReleaseCardCommand.h"

void UseReleaseCardCommand::execute() const
{
	int getPlayersInGameCount = game->getPlayersInGameCount();
	if (getPlayersInGameCount == 0) {
		throw std::invalid_argument("No game in progress. Please start a new game.");
	}

	Player& player = game->getPlayerOnTurn();

	if (!player.isInJail()) {
		throw std::invalid_argument("You are not in jail and you don't have to use a release card, so chill ;)");
	}

	if (!player.getCards()) {
		throw std::invalid_argument("You currently have no release cards! Play and you might get one from the draw card fields.");
	}

	player.removeReleaseCard();
	player.setJailStatus();
	std::cout << std::endl;
	std::cout << "You successfully used a release card. You have " << player.getCards() << " cards left." << std::endl;
	std::cout << std::endl;

	if (game->getRolledStatus()) {
		std::cout << "You are free. You'll will be able to roll next turn." << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "You are free. You can now roll the dice!" << std::endl;
		std::cout << std::endl;
	}
}
