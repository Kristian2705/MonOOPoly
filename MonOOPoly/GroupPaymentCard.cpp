#include "GroupPaymentCard.h"

GroupPaymentCard::GroupPaymentCard(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStrategy)
	: Card(description, effectStrategy)
{ }

void GroupPaymentCard::applyEffect(Player& player) const
{
	effectStrategy->execute(player);
}

Card* GroupPaymentCard::clone() const
{
	return new GroupPaymentCard(*this);
}
