#include "SchoolFee.h"

void SchoolFee::execute(Player& player)
{
	if (GameConstants::SCHOOL_FEE <= player.getMoney()) {
		player.addMoney(-GameConstants::SCHOOL_FEE);
	}
	else {
		//To be implemented
	}
}

CardEffectStrategy* SchoolFee::clone() const
{
	return new SchoolFee(*this);
}
