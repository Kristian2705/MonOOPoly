#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class GoToLocationEffect : public CardEffectStrategy 
{
	size_t locationIndex;
public:
	GoToLocationEffect(size_t locationIndex);
	void execute(Player& player) override;
};