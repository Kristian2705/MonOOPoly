#include "CardDeck.h"

CardDeck::CardDeck() { }

CardDeck* CardDeck::instance = nullptr;

void CardDeck::loadCards()
{
	//To be implemented
}

CardDeck* CardDeck::getInstance()
{
	if (!instance)
	{
		instance = new CardDeck();
		instance->shuffleDeck();
	}

	return instance;
}

void CardDeck::freeInstance()
{
	delete instance;
	instance = nullptr;
}

Card* CardDeck::drawCard()
{
	Card* card = cards[0];
	if (!card) {
		throw new std::invalid_argument("No cards in the deck to draw.");
	}
	return card;
}

void CardDeck::shuffleDeck()
{
	srand(time(NULL));
	int n = cards.getSize();
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		cards.swap(i, j);
	}
}
