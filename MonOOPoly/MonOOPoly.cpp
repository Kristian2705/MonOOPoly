#include <iostream>
#include "Monopoly.h"

int main()
{
	Monopoly* game = Monopoly::getInstance();
	game->startGame();
	Monopoly::freeInstance();
	return 0;
}
