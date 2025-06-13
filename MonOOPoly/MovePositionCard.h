#pragma once
#include "Card.h"
#include "Enums.h"

class MovePositionCard : public Card
{
public:
	MovePositionCard(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStartegy);
	void applyEffect(Player& player) const override;
	Card* clone() const override;
};

