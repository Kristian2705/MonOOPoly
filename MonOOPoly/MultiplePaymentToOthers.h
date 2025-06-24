#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class Monopoly;

class MultiplePaymentToOthers : public CardEffectStrategy
{
	int amount;
public:
	MultiplePaymentToOthers(int amount);
	void execute(Player& player) override;
};

