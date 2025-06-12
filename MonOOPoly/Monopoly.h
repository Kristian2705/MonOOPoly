#pragma once
#include "Constants.h"
#include "Board.h"

class Monopoly
{
	int currentPlayerIndex;
	static Monopoly* instance;
	Board* board;
	Monopoly();
public:
	static Monopoly* getInstance();
	static void freeInstance();
	void startGame();
	void nextTurn();
};

