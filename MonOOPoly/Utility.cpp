#include "Utility.h"

Utility::Utility(int boardIndex, const MyString& name, const MyString& abbreviation)
	: Field(boardIndex, name, abbreviation)
{ }

void Utility::applyEffect()
{
	std::cout << "You landed on a utility field: " << name << ". You can either buy it or pay rent if it's owned." << std::endl;
	// Implement the logic for buying or paying rent for the utility field.
}

Field* Utility::clone() const
{
	return new Utility(*this);
}
