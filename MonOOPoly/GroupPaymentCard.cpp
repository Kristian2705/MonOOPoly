#include "GroupPaymentCard.h"

GroupPaymentCard::GroupPaymentCard(const MyString& description)
	: Card(description)
{ }

void GroupPaymentCard::applyEffect() const
{
}

Card* GroupPaymentCard::clone() const
{
	return new GroupPaymentCard(*this);
}
