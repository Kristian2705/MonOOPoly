#pragma once
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
	int rollDice() const;
	void showPlayerData(int id) const;
	void nextTurn();
};

