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

class Board
{
	Board();
	static Board* instance;
	CardDeck* cardDeck;
	PolymorphicContainer<Field> fields;
	MyVector<Player> players;
	void initializeBoard();
public:
	static Board* getInstance();
	static void freeInstance();
	void addPlayer(const Player& player);
	void removePlayer(int playerId);
	const Player& getPlayer(int playerId) const;
	Player& getPlayer(int playerId);
};

