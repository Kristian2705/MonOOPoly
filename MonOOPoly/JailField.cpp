#include "JailField.h"

JailField::JailField(const MyString& name, const MyString& abbreviation)
	: Field(GameConstants::JAIL_FIELD_INDEX, name, abbreviation)
{ }

void JailField::applyEffect(Player& player)
{
	std::cout << "Just visiting the jail." << std::endl;
}

Field* JailField::clone() const
{
	return new JailField(*this);
}
