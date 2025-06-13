#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class GetOutOfJailEffect : public CardEffectStrategy
{
	bool useNow = false;
public:
	void execute(Player& player) override;
	CardEffectStrategy* clone() const override;
};

