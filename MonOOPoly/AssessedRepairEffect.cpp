#include "AssessedRepairEffect.h"

void AssessedRepairEffect::execute(Player& player)
{
	int sumToPay = 0;
	const MyVector<Property*>& props = player.getOwnedProperties();
	for (int i = 0; i < props.getSize(); i++) {
		int builds = props[i]->getBuildsCount();
		sumToPay += builds * GameConstants::ASSESSED_HOUSE_REPAIR_PRICE;
		if (builds == 5) {
			sumToPay += GameConstants::ASSESSED_HOTEL_REPAIR_PRICE;
		}
	}

	if (sumToPay <= player.getMoney()) {
		player.addMoney(-sumToPay);
	}
	else {
		//To be implemented
	}
}

CardEffectStrategy* AssessedRepairEffect::clone() const
{
	return new AssessedRepairEffect(*this);
}