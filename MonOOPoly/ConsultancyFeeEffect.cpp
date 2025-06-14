#include "ConsultancyFeeEffect.h"

void ConsultancyFeeEffect::execute(Player& player)
{
	player.addMoney(GameConstants::CONSULTANCY_FEE_REWARD);
}

CardEffectStrategy* ConsultancyFeeEffect::clone() const
{
	return new ConsultancyFeeEffect(*this);
}
