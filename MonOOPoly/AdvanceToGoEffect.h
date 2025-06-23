#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"
#include "ConstantsAndFunctions.h"

class AdvanceToGoEffect : public CardEffectStrategy
{
public:
	void execute(Player& player) override;
	CardEffectStrategy* clone() const override;
};

