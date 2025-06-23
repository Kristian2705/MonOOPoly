#include "NewGameCommand.h"

void NewGameCommand::execute() const
{
	game->welcomePlayers();
}
