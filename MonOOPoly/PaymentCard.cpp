#include "PaymentCard.h"

PaymentCard::PaymentCard(const MyString& description)
	: Card(description)
{ }

void PaymentCard::applyEffect() const
{
}

Card* PaymentCard::clone() const
{
	return new PaymentCard(*this);
}

