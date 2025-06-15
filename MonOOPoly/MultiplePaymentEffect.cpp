#include "MultiplePaymentEffect.h"
#include "Monopoly.h"

MultiplePaymentEffect::MultiplePaymentEffect(int amount)
	: amount(amount)
{ }

void MultiplePaymentEffect::execute(Player& player)
{
	MyVector<Player>& players = Monopoly::getInstance()->getPlayers();
	for (int i = 0; i < players.getSize(); i++) {
		if (amount <= players[i].getMoney()) {
			players[i].addMoney(-amount);
			player.addMoney(amount);
		}
		else {
			//To be implemented
		}
	}
}

CardEffectStrategy* MultiplePaymentEffect::clone() const
{
	return new MultiplePaymentEffect(*this);
}
