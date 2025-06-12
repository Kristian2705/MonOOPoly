#pragma once
#include "Field.h"

class TaxField : public Field
{
	int taxAmount;
public:
	TaxField() = delete;
	TaxField(int boardIndex, const MyString& name, int taxAmount);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

