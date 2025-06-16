#include "GoToLocationEffect.h"

GoToLocationEffect::GoToLocationEffect(size_t locationIndex)
	: locationIndex(locationIndex)
{ }

void GoToLocationEffect::execute(Player& player)
{
	if (player.getCurrentPosition() > locationIndex) {
		std::cout << "You passed GO! Collect $200!";
		player.addMoney(GameConstants::PASS_GO_BONUS);
	}
	player.moveTo(locationIndex);
}

CardEffectStrategy* GoToLocationEffect::clone() const
{
	return new GoToLocationEffect(*this);
}
