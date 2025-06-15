#include "GoField.h"
#include "Player.h"

GoField::GoField(const MyString& name, const MyString& abbreviation)
	: Field(GameConstants::GO_FIELD_INDEX, name, abbreviation)
{ }

void GoField::applyEffect(Player& player)
{
	player.addMoney(GameConstants::PASS_GO_BONUS);
	std::cout << "You passed GO! Collect $200." << std::endl;
}

Field* GoField::clone() const
{
	return new GoField(*this);
}
