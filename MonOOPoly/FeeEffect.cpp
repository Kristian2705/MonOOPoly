#include "FeeEffect.h"

FeeEffect::FeeEffect(int amount)
	: amount(amount)
{ }

void FeeEffect::execute(Player& player)
{
	if (amount <= player.getMoney())
	{
		player.addMoney(-amount);
	}
	else {
		player.setInDebtStatus();
		std::cout << "You don't have enough money to pay your debt to the bank." << std::endl;
		std::cout << "You owe $" << amount << " but you have $" << player.getMoney() << std::endl;
		std::cout << "Find a way to collect the money or go bankrupt." << std::endl;
	}
}

CardEffectStrategy* FeeEffect::clone() const
{
	return new FeeEffect(*this);
}
