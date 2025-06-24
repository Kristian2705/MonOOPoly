#include "NewGameCommand.h"

void NewGameCommand::execute() const
{
	if (game->getPlayersInGameCount()) {
		throw std::invalid_argument("A game is already in progress. Please finish it before starting a new one.");
	}
	game->welcomePlayers();
}
