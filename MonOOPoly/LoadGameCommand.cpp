#include "LoadGameCommand.h"

void LoadGameCommand::execute() const
{
	if (game->getPlayersInGameCount()) 
	{
		throw std::invalid_argument("Cannot load a game while another is in progress.");
	}
	game->loadFromBinaryFile();
}
