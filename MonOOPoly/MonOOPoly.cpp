#include <iostream>
#include "Monopoly.h"

int main()
{
	CardDeck* deck = CardDeck::getInstance();
	deck->showCards();
	//Monopoly* game = Monopoly::getInstance();
	//game->startGame();
	//Monopoly::freeInstance();
	return 0;
}
