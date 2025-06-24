#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class GoToNearestRailroadEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
};

