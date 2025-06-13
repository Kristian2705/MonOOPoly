#include "PaymentCard.h"

PaymentCard::PaymentCard(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStrategy)
	: Card(description, effectStrategy)
{ }

void PaymentCard::applyEffect(Player& player) const
{
	effectStrategy->execute(player);
}

Card* PaymentCard::clone() const
{
	return new PaymentCard(*this);
}

