#include "TaxField.h"

TaxField::TaxField(int boardIndex, const MyString& name, const MyString& abbreviation, int taxAmount)
	: Field(boardIndex, name, abbreviation), taxAmount(taxAmount)
{ }

void TaxField::applyEffect()
{

}

Field* TaxField::clone() const
{
	return new TaxField(*this);
}


