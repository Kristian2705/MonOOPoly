#include "SaveGameCommand.h"

void SaveGameCommand::execute() const
{
	if (!game->getPlayersInGameCount()) {
		throw std::invalid_argument("No game in progress to save.");
	}
	game->saveToBinaryFile();
}
