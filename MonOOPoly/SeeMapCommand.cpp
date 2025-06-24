#include "SeeMapCommand.h"

void SeeMapCommand::execute() const
{
	Monopoly* game = Monopoly::getInstance();

	//if (game->getPlayersInGameCount() == 0) {
	//	throw std::invalid_argument("No game in progress. Please start a new game.");
	//}

	game->showMap();
}
