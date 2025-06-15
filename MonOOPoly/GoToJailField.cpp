#include "GoToJailField.h"
#include "Player.h"

GoToJailField::GoToJailField(const MyString & name, const MyString& abbreviation)
	: Field(GameConstants::GO_TO_JAIL_FIELD_INDEX, name, abbreviation)
{
}

void GoToJailField::applyEffect(Player& player)
{
	player.setJailStatus();
	std::cout << "You have been sent to jail! You can pay $100 and play next turn or wait for 3 turns." << std::endl;
}

Field* GoToJailField::clone() const
{
	return new GoToJailField(*this);
}
