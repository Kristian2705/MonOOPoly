#pragma once
#include "MyVector.hpp"
#include "Card.h"

class CardDeck
{
	CardDeck();
	static CardDeck* instance;
	MyVector<Card*> cards;

	void loadCards();
public:
	static CardDeck* getInstance();
	static void freeInstance();
	void showCards();
	Card* drawCard();
	void shuffleDeck();
};

