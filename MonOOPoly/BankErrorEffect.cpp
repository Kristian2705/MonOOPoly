#include "BankErrorEffect.h"

void BankErrorEffect::execute(Player& player)
{
	player.addMoney(GameConstants::BANK_ERROR_REWARD);
}

CardEffectStrategy* BankErrorEffect::clone() const
{
	return new BankErrorEffect(*this);
}
