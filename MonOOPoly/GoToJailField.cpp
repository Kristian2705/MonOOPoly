#include "GoToJailField.h"

GoToJailField::GoToJailField(const MyString & name)
	: Field(GameConstants::GO_TO_JAIL_FIELD_INDEX, name)
{
}

void GoToJailField::putInJail(Player & player) const
{
	player.setJailStatus();
}

void GoToJailField::applyEffect(Player& player)
{
	putInJail(player);
}

Field* GoToJailField::clone() const
{
	return new GoToJailField(*this);
}
