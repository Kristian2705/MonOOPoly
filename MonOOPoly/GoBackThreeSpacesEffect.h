#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class GoBackThreeSpacesEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
};

