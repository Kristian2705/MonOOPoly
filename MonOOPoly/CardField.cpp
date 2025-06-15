#include "CardField.h"
#include "Monopoly.h"

CardField::CardField(int id, const MyString& name, const MyString& abbreviation)
	: Field(id, name, abbreviation)
{
	deck = CardDeck::getInstance();
}

void CardField::applyEffect(Player& player)
{
	Card* card = deck->drawCard();
	card->applyEffect(player);
}

Field* CardField::clone() const
{
	return new CardField(*this);
}
