#pragma once
#include "PolymorphicContainer.hpp"
#include "Card.h"

class CardDeck
{
	CardDeck();
	static CardDeck* instance;
	PolymorphicContainer<Card> cards;
public:
	static CardDeck* getInstance();
	static void freeInstance();
	void drawCard();
	void shuffleDeck();
};

