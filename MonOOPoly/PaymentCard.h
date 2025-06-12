#pragma once
#include "Card.h"

class PaymentCard : public Card
{
public:
	PaymentCard(const MyString& description);
	void applyEffect() const override;
	Card* clone() const override;
};

