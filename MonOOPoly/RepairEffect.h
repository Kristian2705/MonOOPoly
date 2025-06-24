#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class RepairEffect : public CardEffectStrategy
{
	int houseCost;
	int hotelCost;
public:
	RepairEffect(int houseCost, int hotelCost);
	void execute(Player& player) override;
};

