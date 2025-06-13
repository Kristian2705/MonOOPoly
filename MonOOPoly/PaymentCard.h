#pragma once
#include "Card.h"

class PaymentCard : public Card
{
public:
	PaymentCard(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStrategy);
	void applyEffect(Player& player) const override;
	Card* clone() const override;
};

