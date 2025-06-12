#include "Monopoly.h"

Monopoly::Monopoly() : currentPlayerIndex(GameConstants::FIRST_PLAYER_ID) { }

Monopoly* Monopoly::instance = nullptr;

Monopoly* Monopoly::getInstance()
{
	if (!instance)
	{
		instance = new Monopoly();
	}

	return instance;
}

void Monopoly::freeInstance()
{
	delete instance;
	instance = nullptr;
}

void Monopoly::startGame()
{
	board = Board::getInstance();
}

//void Monopoly::nextTurn()
//{
//	currentPlayerIndex++;
//	if (currentPlayerIndex >= GameConstants::MAX_PLAYERS)
//	{
//		currentPlayerIndex = GameConstants::FIRST_PLAYER_ID;
//	}
//}
