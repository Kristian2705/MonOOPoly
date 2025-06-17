#include "FeeEffect.h"

FeeEffect::FeeEffect(int amount)
	: amount(amount)
{ }

void FeeEffect::execute(Player& player)
{
	if (amount <= player.getMoney())
	{
		player.addMoney(-amount);
	}
	else {
		//To be implemented
	}
}

CardEffectStrategy* FeeEffect::clone() const
{
	return new FeeEffect(*this);
}
