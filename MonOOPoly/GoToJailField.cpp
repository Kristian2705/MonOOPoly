#include "GoToJailField.h"

GoToJailField::GoToJailField(const MyString & name, const MyString& abbreviation)
	: Field(GameConstants::GO_TO_JAIL_FIELD_INDEX, name, abbreviation)
{
}

//void GoToJailField::putInJail() const
//{
//	player.setJailStatus();
//}

void GoToJailField::applyEffect()
{

}

Field* GoToJailField::clone() const
{
	return new GoToJailField(*this);
}
