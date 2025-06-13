#include "GoField.h"

GoField::GoField(const MyString& name, const MyString& abbreviation)
	: Field(GameConstants::GO_FIELD_INDEX, name, abbreviation)
{ }

void GoField::applyEffect()
{
	std::cout << "You passed GO! Collect $200." << std::endl;
}

Field* GoField::clone() const
{
	return new GoField(*this);
}
