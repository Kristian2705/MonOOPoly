#include "MultiplePaymentEffect.h"
#include "Monopoly.h"

MultiplePaymentEffect::MultiplePaymentEffect(int amount)
	: amount(amount)
{ }

void MultiplePaymentEffect::execute(Player& player)
{
	MyVector<Player>& players = Monopoly::getInstance()->getPlayers();
	for (int i = 0; i < players.getSize(); i++) {
		if(&players[i] == &player || !players[i].isInGame())
			continue;
		if (amount <= players[i].getMoney()) {
			players[i].addMoney(-amount);
			player.addMoney(amount);
		}
		else {
			players[i].setInDebtStatus();
			std::cout << players[i].getName() <<", you don't have enough money to pay your debt to " << player.getName() << std::endl;
			std::cout << "You owe $" << amount << " but you have $" << players[i].getMoney() << std::endl;
			std::cout << "Find a way to collect the money or go bankrupt." << std::endl;
			players[i].setInDebtTo(&player);
			players[i].setOwedMoney(amount);
			break;
		}
	}
}
