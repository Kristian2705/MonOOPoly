#pragma once
#include "Player.h"
#include "CardDeck.h"

class Board
{
	Board();
	static Board* instance;
	CardDeck* cardDeck;
	Field* fields[GameConstants::BOARD_SIZE];
	MyVector<Player> players;
public:
	static Board* getInstance();
	static void freeInstance();
};

