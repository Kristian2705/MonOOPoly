#include "GoToStCharlesEffect.h"

void GoToStCharlesEffect::execute(Player& player)
{
	if (player.getCurrentPosition() > GameConstants::ST_CHARLES_LOCATION) {
		std::cout << "You passed GO! Collect $200!";
		player.addMoney(GameConstants::PASS_GO_BONUS);
	}
	player.moveTo(GameConstants::ST_CHARLES_LOCATION);
	std::cout << "You are currently on position " << player.getCurrentPosition() << std::endl;
}

CardEffectStrategy* GoToStCharlesEffect::clone() const
{
	return new GoToStCharlesEffect(*this);
}
