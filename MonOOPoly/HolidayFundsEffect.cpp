#include "HolidayFundsEffect.h"

void HolidayFundsEffect::execute(Player& player)
{
	player.addMoney(GameConstants::HOLIDAY_FUNDS_REWARD);
}

CardEffectStrategy* HolidayFundsEffect::clone() const
{
	return new HolidayFundsEffect(*this);
}
