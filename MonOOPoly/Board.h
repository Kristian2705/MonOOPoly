#pragma once
#include "Player.h"
#include "CardDeck.h"
#include "GoToJailField.h"
#include "GoField.h"
#include "CardField.h"
#include "JailField.h"
#include "ParkingField.h"
#include "TaxField.h"
#include "Station.h"
#include "Utility.h"
#include "PolymorphicContainer.hpp"
#include <iomanip>

class Board
{
	Board();
	static Board* instance;
	PolymorphicContainer<Field> fields;
	void initializeBoard();
	void printCell(const MyString& label) const;
	void printTopRow() const;
	void printBottomRow() const;
	void printMiddleRows() const;
public:
	static Board* getInstance();
	static void freeInstance();
	void printBoard() const;
	void stepOn(size_t position, Player& player);
};

