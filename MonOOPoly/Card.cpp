#include "Card.h"

Card::Card(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStrategy)
	: description(description), effectStrategy(std::move(effectStrategy))
{ }

const MyString& Card::getDescription() const
{
	return description;
}

void Card::applyEffect(Player& player)
{
	std::cout << description << std::endl;
	effectStrategy->execute(player);
}
