#include "MovePositionCard.h"

MovePositionCard::MovePositionCard(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStrategy)
	: Card(description, effectStrategy)
{ }

void MovePositionCard::applyEffect(Player& player) const
{
	effectStrategy->execute(player);
}

Card* MovePositionCard::clone() const
{
	return new MovePositionCard(*this);
}
