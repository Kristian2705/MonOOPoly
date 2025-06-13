#pragma once
#include "Field.h"

class TaxField : public Field
{
	int taxAmount;
public:
	TaxField(int boardIndex, const MyString& name, const MyString& abbreviation, int taxAmount);
	void applyEffect() override;
	Field* clone() const override;
};

