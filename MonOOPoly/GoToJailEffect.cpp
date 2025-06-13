#include "GoToJailEffect.h"

void GoToJailEffect::execute(Player& player)
{
	player.setJailStatus();
}

CardEffectStrategy* GoToJailEffect::clone() const
{
	return new GoToJailEffect(*this);
}
