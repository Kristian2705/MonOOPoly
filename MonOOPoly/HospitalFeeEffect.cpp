#include "HospitalFeeEffect.h"

void HospitalFeeEffect::execute(Player& player)
{
	if (GameConstants::HOSPITAL_FEE <= player.getMoney()) {
		player.addMoney(-GameConstants::HOSPITAL_FEE);
	}
	else {
		//To be implemented
	}
}

CardEffectStrategy* HospitalFeeEffect::clone() const
{
	return new HospitalFeeEffect(*this);
}
