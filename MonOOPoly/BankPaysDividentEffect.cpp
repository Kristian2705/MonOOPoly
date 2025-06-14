#include "BankPaysDividentEffect.h"

void BankPaysDividentEffect::execute(Player& player)
{
	player.addMoney(GameConstants::BANK_DIVIDENT_REWARD);
}

CardEffectStrategy* BankPaysDividentEffect::clone() const
{
	return new BankPaysDividentEffect(*this);
}
