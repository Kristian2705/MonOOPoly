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
	Monopoly::getInstance()->resetPairStatus();
	std::cout << "You have been sent to jail! Next turn you can pay $50 and play or wait for 3 turns." << std::endl;
}

Field* GoToJailField::clone() const
{
	return new GoToJailField(*this);
}
