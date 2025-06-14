#include "InheritanceEffect.h"

void InheritanceEffect::execute(Player& player)
{
	player.addMoney(GameConstants::INHERITANCE_REWARD);
}

CardEffectStrategy* InheritanceEffect::clone() const
{
	return new InheritanceEffect(*this);
}
