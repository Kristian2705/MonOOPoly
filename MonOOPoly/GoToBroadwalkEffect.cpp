#include "GoToBroadwalkEffect.h"

void GoToBroadwalkEffect::execute(Player& player)
{
	player.moveTo(GameConstants::ILLINOIS_LOCATION);
	std::cout << "You are currently on position " << player.getCurrentPosition() << std::endl;
}

CardEffectStrategy* GoToBroadwalkEffect::clone() const
{
	return new GoToBroadwalkEffect(*this);
}
