#include "GoToJailField.h"
#include "Player.h"
#include "Monopoly.h"

GoToJailField::GoToJailField(const MyString & name, const MyString& abbreviation)
	: Field(GameConstants::GO_TO_JAIL_FIELD_INDEX, name, abbreviation)
{
}

void GoToJailField::applyEffect(Player& player)
{
	player.setJailStatus();
	std::cout << "You have been sent to jail! Next turn you can pay $50 and play or wait for 3 turns." << std::endl;
	Monopoly::getInstance()->resetPairStatus();
	player.moveTo(GameConstants::JAIL_FIELD_INDEX);
}

void GoToJailField::saveToBinary(std::ofstream& ofs) const
{
	return;
}

void GoToJailField::loadFromBinary(std::ifstream& ifs)
{
	return;
}

Field* GoToJailField::clone() const
{
	return new GoToJailField(*this);
}
