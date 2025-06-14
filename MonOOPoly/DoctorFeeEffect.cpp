#include "DoctorFeeEffect.h"

void DoctorFeeEffect::execute(Player& player)
{
	if (GameConstants::DOCTOR_FEE <= player.getMoney())
	{
		player.addMoney(-GameConstants::DOCTOR_FEE);
	}
	else {
		//To be implemented
	}
}

CardEffectStrategy* DoctorFeeEffect::clone() const
{
	return new DoctorFeeEffect(*this);
}
