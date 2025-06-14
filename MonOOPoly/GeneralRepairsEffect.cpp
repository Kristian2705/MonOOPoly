#include "GeneralRepairsEffect.h"

void GeneralRepairsEffect::execute(Player& player)
{
	int sumToPay = 0;
	const MyVector<Property*>& props = player.getOwnedProperties();
	for (int i = 0; i < props.getSize(); i++) {
		int builds = props[i]->getBuildsCount();
		sumToPay += builds * GameConstants::REPAIR_HOUSE_PRICE;
		if (builds == 5) {
			sumToPay += GameConstants::REPAIR_HOTEL_PRICE;
		}
	}

	if (sumToPay <= player.getMoney()) {
		player.addMoney(-sumToPay);
	}
	else {
		//To be implemented
	}
}

CardEffectStrategy* GeneralRepairsEffect::clone() const
{
	return new GeneralRepairsEffect(*this);
}
