#include "CardField.h"

CardField::CardField(int id, const MyString& name)
	: Field(id, name)
{ }

void CardField::applyEffect(Player& player)
{
	// Implement the effect of the card field on the player
	// For example, draw a card from the deck and apply its effect
	// This is a placeholder implementation
	//player.drawCard();
	std::cout << "Draw card" << std::endl;
}

Field* CardField::clone() const
{
	return new CardField(*this);
}
