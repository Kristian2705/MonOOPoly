#include "RepairEffect.h"

RepairEffect::RepairEffect(int houseCost, int hotelCost)
	: houseCost(houseCost), hotelCost(hotelCost)
{ }

void RepairEffect::execute(Player& player)
{
	int sumToPay = 0;
	const MyVector<Property*>& props = player.getOwnedProperties();
	int builds = 0;
	for (int i = 0; i < props.getSize(); i++) {
		builds = props[i]->getBuildsCount();
	}
	if (!builds) {
		std::cout << "You haven't built anything yet so you are chilling." << std::endl;
	}
	for (int i = 0; i < props.getSize(); i++) {
		int builds = props[i]->getBuildsCount();
		sumToPay += builds * houseCost;
		if (builds == 5) {
			sumToPay += hotelCost;
			sumToPay -= houseCost;
		}
	}

	if (sumToPay <= player.getMoney()) {
		player.addMoney(-sumToPay);
	}
	else {
		player.setInDebtStatus();
		std::cout << "You don't have enough money to pay your debt to the bank." << std::endl;
		std::cout << "You owe $" << sumToPay << " but you have $" << player.getMoney() << std::endl;
		std::cout << "Find a way to collect the money or go bankrupt." << std::endl;
		player.setOwedMoney(sumToPay);
	}
}

CardEffectStrategy* RepairEffect::clone() const
{
	return new RepairEffect(*this);
}
