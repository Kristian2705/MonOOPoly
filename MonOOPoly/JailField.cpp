#include "JailField.h"

JailField::JailField(const MyString& name)
	: Field(GameConstants::JAIL_FIELD_INDEX, name)
{ }

void JailField::applyEffect(Player& player)
{
	std::cout << "Just visiting the jail." << std::endl;
}

Field* JailField::clone() const
{
	return new JailField(*this);
}
