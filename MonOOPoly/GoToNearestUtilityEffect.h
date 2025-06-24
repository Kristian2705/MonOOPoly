#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class GoToNearestUtilityEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
};

