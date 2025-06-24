#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class FeeEffect : public CardEffectStrategy
{
	int amount;
public:
	FeeEffect(int amount);
	void execute(Player& player) override;
};

