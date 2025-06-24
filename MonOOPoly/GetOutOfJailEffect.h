#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class GetOutOfJailEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
};

