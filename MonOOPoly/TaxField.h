#pragma once
#include "Field.h"

class Monopoly;

class TaxField : public Field
{
	int taxAmount;
public:
	TaxField(int boardIndex, const MyString& name, const MyString& abbreviation, int taxAmount);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

