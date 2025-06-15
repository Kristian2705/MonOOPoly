#include "MultiplePaymentToOthers.h"
#include "Monopoly.h"

MultiplePaymentToOthers::MultiplePaymentToOthers(int amount)
	: amount(amount)
{ }

void MultiplePaymentToOthers::execute(Player & player)
{
	MyVector<Player>& players = Monopoly::getInstance()->getPlayers();
	if (amount * players.getSize() <= player.getMoney()) {
		for (int i = 0; i < players.getSize(); i++) {
			players[i].addMoney(amount);
			player.addMoney(-amount);
		}
	}
	else {
		//To be implemented
	}
}

CardEffectStrategy* MultiplePaymentToOthers::clone() const
{
	return new MultiplePaymentToOthers(*this);
}


