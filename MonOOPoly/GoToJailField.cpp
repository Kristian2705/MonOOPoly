#include "GoToJailField.h"

GoToJailField::GoToJailField()
	: Field(10)
{ }

void GoToJailField::putInJail(Player & player) const
{
	player.setJailStatus();
}

Field* GoToJailField::clone() const
{
	return new GoToJailField(*this);
}
