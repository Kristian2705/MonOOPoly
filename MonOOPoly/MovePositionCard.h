#pragma once
#include "Card.h"
#include "Enums.h"

class MovePositionCard : public Card
{
	MoveTypes moveType;
	//implement applyEffect for each MoveType
public:
	MovePositionCard(const MyString& description, MoveTypes moveType);
	void applyEffect() const override;
	Card* clone() const override;
};

