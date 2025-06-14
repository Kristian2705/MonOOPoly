#include "IncomeTaxRefundEffect.h"

void IncomeTaxRefundEffect::execute(Player& player)
{
	player.addMoney(GameConstants::INCOME_TAX_REFUND);
}

CardEffectStrategy* IncomeTaxRefundEffect::clone() const
{
	return nullptr;
}
