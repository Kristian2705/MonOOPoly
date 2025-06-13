#include "Card.h"

Card::Card(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStrategy)
	: description(description), effectStrategy(std::move(effectStrategy))
{ }

void Card::applyEffect(Player& player)
{
	effectStrategy->execute(player);
}
