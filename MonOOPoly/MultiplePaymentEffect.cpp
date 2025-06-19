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
			players[i].setInDebtStatus();
			std::cout << "You don't have enough money to pay your debt to " << player.getName() << std::endl;
			std::cout << "You owe $" << amount << " but you have $" << players[i].getMoney() << std::endl;
			std::cout << "Find a way to collect the money or go bankrupt." << std::endl;
			break;
		}
	}
}

CardEffectStrategy* MultiplePaymentEffect::clone() const
{
	return new MultiplePaymentEffect(*this);
}
