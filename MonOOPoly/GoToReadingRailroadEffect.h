#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class GoToReadingRailroadEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
	CardEffectStrategy* clone() const override;
};

