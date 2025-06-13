#include "GoToIllinoisEffect.h"

void GoToIllinoisEffect::execute(Player& player)
{
	if (player.getCurrentPosition() > GameConstants::ILLINOIS_LOCATION) {
		std::cout << "You passed GO! Collect $200!";
		player.addMoney(GameConstants::PASS_GO_BONUS);
	}
	player.moveTo(GameConstants::ILLINOIS_LOCATION);
	std::cout << "You are currently on position " << player.getCurrentPosition() << std::endl;
}

CardEffectStrategy* GoToIllinoisEffect::clone() const
{
	return new GoToIllinoisEffect(*this);
}
