#include "GoField.h"

GoField::GoField(const MyString& name)
	: Field(GameConstants::GO_FIELD_INDEX, name)
{ }

void GoField::applyEffect(Player& player)
{
	std::cout << "You passed GO! Collect $200." << std::endl;
	player.addMoney(GameConstants::PASS_GO_BONUS);
}

Field* GoField::clone() const
{
	return new GoField(*this);
}
