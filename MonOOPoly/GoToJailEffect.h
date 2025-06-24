#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class GoToJailEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
};

