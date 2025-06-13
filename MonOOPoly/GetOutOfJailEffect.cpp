#include "GetOutOfJailEffect.h"

void GetOutOfJailEffect::execute(Player& player)
{
	if (!player.isInJail()) {
		throw std::invalid_argument("You can only use this card if you are in jail!");
	}
	//I will think of this logic later on
}

CardEffectStrategy* GetOutOfJailEffect::clone() const
{
	return new GetOutOfJailEffect(*this);
}
