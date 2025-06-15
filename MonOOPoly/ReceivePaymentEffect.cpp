#include "ReceivePaymentEffect.h"

ReceivePaymentEffect::ReceivePaymentEffect(int amount)
	: amount(amount)
{ }

void ReceivePaymentEffect::execute(Player& player)
{
	player.addMoney(amount);
}

CardEffectStrategy* ReceivePaymentEffect::clone() const
{
	return new ReceivePaymentEffect(*this);
}
