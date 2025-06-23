#include "MultiplePaymentToOthers.h"
#include "Monopoly.h"

MultiplePaymentToOthers::MultiplePaymentToOthers(int amount)
	: amount(amount)
{ }

void MultiplePaymentToOthers::execute(Player & player)
{
	MyVector<Player>& players = Monopoly::getInstance()->getPlayers();
	int amountToPay = amount * (Monopoly::getInstance()->getPlayersInGameCount() - 1);
	if (amountToPay <= player.getMoney()) {
		for (int i = 0; i < players.getSize(); i++) {
			if(&players[i] == &player || !players[i].isInGame())
				continue;
			players[i].addMoney(amount);
			player.addMoney(-amount);
		}
	}
	else {
		for (int i = 0; i < players.getSize(); i++) {
			if(&players[i] == &player || !players[i].isInGame())
				continue;
			players[i].addMoney(amount);
		}
		player.setInDebtStatus();
		std::cout << "You don't have enough money to pay your debt to everyone." << std::endl;
		std::cout << "You owe $" << amountToPay << " but you have $" << player.getMoney() << std::endl;
		std::cout << "Find a way to collect the money or go bankrupt." << std::endl;
		player.setOwedMoney(amountToPay);
	}
}

CardEffectStrategy* MultiplePaymentToOthers::clone() const
{
	return new MultiplePaymentToOthers(*this);
}


