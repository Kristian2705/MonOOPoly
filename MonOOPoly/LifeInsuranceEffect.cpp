#include "LifeInsuranceEffect.h"

void LifeInsuranceEffect::execute(Player& player)
{
	player.addMoney(GameConstants::LIFE_INSURANCE);
}

CardEffectStrategy* LifeInsuranceEffect::clone() const
{
	return new LifeInsuranceEffect(*this);
}
