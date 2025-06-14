#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class HospitalFeeEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
	CardEffectStrategy* clone() const override;
};

