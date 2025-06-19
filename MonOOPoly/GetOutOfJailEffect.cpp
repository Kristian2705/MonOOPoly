#include "GetOutOfJailEffect.h"

void GetOutOfJailEffect::execute(Player& player)
{
	player.addReleaseCard();
}

CardEffectStrategy* GetOutOfJailEffect::clone() const
{
	return new GetOutOfJailEffect(*this);
}
