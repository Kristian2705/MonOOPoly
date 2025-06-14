#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class Monopoly;

class OperaNightEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
	CardEffectStrategy* clone() const override;
};

