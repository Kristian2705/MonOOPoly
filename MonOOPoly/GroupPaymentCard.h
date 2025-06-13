#pragma once
#include "Card.h"

class GroupPaymentCard : public Card
{
public:
	GroupPaymentCard(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStrategy);
	void applyEffect(Player& player) const override;
	Card* clone() const override;
};

