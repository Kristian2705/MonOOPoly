#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class Monopoly;

class MultiplePaymentEffect : public CardEffectStrategy
{
	int amount;
public:
	MultiplePaymentEffect(int amount);
	void execute(Player& player) override;
	CardEffectStrategy* clone() const override;
};

