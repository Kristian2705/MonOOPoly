#pragma once
#include "Card.h"

class GroupPaymentCard : public Card
{
public:
	GroupPaymentCard(const MyString& description);
	void applyEffect() const override;
	Card* clone() const override;
};

