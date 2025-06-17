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
		}
	}

	if (sumToPay <= player.getMoney()) {
		player.addMoney(-sumToPay);
	}
	else {
		//To be implemented
	}
}

CardEffectStrategy* RepairEffect::clone() const
{
	return new RepairEffect(*this);
}
