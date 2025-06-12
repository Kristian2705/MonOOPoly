#include "Board.h"

Board::Board()
{
	//load default data
}

Board* Board::instance = nullptr;

Board* Board::getInstance()
{
    if (!instance) {
		instance = new Board();
    }
	return instance;
}

void Board::freeInstance()
{
	delete instance;
	instance = nullptr;
}