#include "Trade.h"
#include "Player.h"

void Trade::show() const
{
	if (!propertyToGet && !propertyToGive && !stationToGet && !stationToGive && !utilityToGet && !utilityToGive && !moneyToGet && !moneyToGive) {
		std::cout << "The trade window is empty! Try selecting something first!" << std::endl;
		return;
	}

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "This is the current state of the trade window: " << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Properties: " << std::endl;
	std::cout << "<-Property to get: " << ((propertyToGet) ? propertyToGet->getName() : "none") << std::endl;
	std::cout << "->Property to give: " << ((propertyToGive) ? propertyToGive->getName() : "none") << std::endl;
	std::cout << std::endl;
	std::cout << "Stations: " << std::endl;
	std::cout << "<-Station to get: " << ((stationToGet) ? stationToGet->getName() : "none") << std::endl;
	std::cout << "->Station to give: " << ((stationToGive) ? stationToGive->getName() : "none") << std::endl;
	std::cout << std::endl;
	std::cout << "Utilities: " << std::endl;
	std::cout << "<-Utilities to get: " << ((utilityToGet) ? utilityToGet->getName() : "none") << std::endl;
	std::cout << "->Utilities to give: " << ((utilityToGive) ? utilityToGive->getName() : "none") << std::endl;
	std::cout << std::endl;
	std::cout << "Money: " << std::endl;
	std::cout << "<-Money to get: $" << moneyToGet << std::endl;
	std::cout << "->Money to give: $" << moneyToGive << std::endl;
}

void Trade::clear()
{
	sender = nullptr;
	receiver = nullptr;

	propertyToGet = nullptr;
	propertyToGive = nullptr;

	stationToGet = nullptr;
	stationToGive = nullptr;

	utilityToGet = nullptr;
	utilityToGive = nullptr;

	moneyToGet = 0;
	moneyToGive = 0;
}

void Trade::initiate()
{
	if (propertyToGive) {
		sender->removeProperty(propertyToGive);
		propertyToGive->setOwner(receiver);
		propertyToGive->resetRentTier();
		receiver->addProperty(propertyToGive);
	}

	if (propertyToGet) {
		receiver->removeProperty(propertyToGet);
		propertyToGet->setOwner(sender);
		propertyToGet->resetRentTier();
		sender->addProperty(propertyToGet);
	}

	if (stationToGive) {
		sender->removeStation(stationToGive);
		stationToGive->setOwner(receiver);
		stationToGive->resetRentTier();
		receiver->addStation(stationToGive);
	}

	if (stationToGet) {
		receiver->removeStation(stationToGet);
		stationToGet->setOwner(sender);
		stationToGet->resetRentTier();
		sender->addStation(stationToGet);
	}

	if (utilityToGive) {
		sender->removeUtility(utilityToGive);
		utilityToGive->setOwner(receiver);
		utilityToGive->decreaseRentMultiplier();
		receiver->addUtility(utilityToGive);
	}

	if (utilityToGet) {
		receiver->removeUtility(utilityToGet);
		utilityToGet->setOwner(sender);
		utilityToGet->decreaseRentMultiplier();
		sender->addUtility(utilityToGet);
	}

	sender->addMoney((-1) * moneyToGive);
	sender->addMoney(moneyToGet);
	receiver->addMoney(moneyToGive);
	receiver->addMoney((-1) * moneyToGet);
}


