#include "TaxField.h"

TaxField::TaxField(int boardIndex, const MyString& name, int taxAmount)
	: Field(boardIndex, name), taxAmount(taxAmount)
{ }

void TaxField::applyEffect(Player& player)
{
	player.addMoney(-taxAmount);
}

Field* TaxField::clone() const
{
	return new TaxField(*this);
}


