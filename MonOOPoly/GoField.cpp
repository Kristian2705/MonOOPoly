#include "GoField.h"
#include "Player.h"

GoField::GoField(const MyString& name, const MyString& abbreviation)
	: Field(GameConstants::GO_FIELD_INDEX, name, abbreviation)
{ }

void GoField::applyEffect(Player& player)
{
	std::cout << "GO Collect $200.00 salary as you pass!" << std::endl;
}

void GoField::saveToBinary(std::ofstream& ofs) const
{
	return;
}

void GoField::loadFromBinary(std::ifstream& ifs)
{
	return;
}
