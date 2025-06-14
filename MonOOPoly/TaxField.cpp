#include "TaxField.h"
#include "Monopoly.h"

TaxField::TaxField(int boardIndex, const MyString& name, const MyString& abbreviation, int taxAmount)
	: Field(boardIndex, name, abbreviation), taxAmount(taxAmount)
{ }

void TaxField::applyEffect()
{
	Player& cP = Monopoly::getInstance()->getPlayerOnTurn();
	if (taxAmount <= cP.getMoney()) {
		cP.addMoney(-taxAmount);
	}
	else {
		//To be implemented
	}
}

Field* TaxField::clone() const
{
	return new TaxField(*this);
}


