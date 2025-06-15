#pragma once
#include "CardEffectStrategy.h"
#include "Player.h"

class ReceivePaymentEffect : public CardEffectStrategy
{
	int amount;
public:
	ReceivePaymentEffect(int amount);
	void execute(Player& player) override;
	CardEffectStrategy* clone() const override;
};

