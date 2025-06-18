#include "SellCommand.h"

void SellCommand::execute() const
{
	Player& player = game->getPlayerOnTurn();

	if (player.isInJail()) {
		throw std::invalid_argument("Get out of jail first and then try selling!");
	}

	const MyVector<Property*>& ownedProps = player.getOwnedProperties();

	if (!ownedProps.getSize()) {
		throw std::invalid_argument("You don't have any properties to mortgage!");
	}

	MyVector<Property*> validPropsForBuilding;
	for (int i = 0; i < ownedProps.getSize(); i++) {
		int rentTierIndex = ownedProps[i]->getRentTierIndex();
		if (rentTierIndex >= 1) {
			validPropsForBuilding.push_back(ownedProps[i]);
		}
	}

	if (!validPropsForBuilding.getSize()) {
		throw std::invalid_argument("No eligible properties to sell buildings on!");
	}

	std::cout << "Here are all the properties on which you can sell buildings!" << std::endl;
	for (int i = 0; i < validPropsForBuilding.getSize(); i++) {
		validPropsForBuilding[i]->showProperty();
		std::cout << std::endl;
	}

	while (true) {
		bool readyToSell = true;
		while (true) {
			std::cout << "Ready to sell? Type 'yes' or 'no'" << std::endl;
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				readyToSell = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!readyToSell) {
			break;
		}

		Property* propToSellOn = nullptr;
		int position = 0;
		while (true) {
			std::cout << "You currently have $" << player.getMoney() << std::endl;
			std::cout << "Please enter the position of the property you'd like to sell on!" << std::endl;

			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (!str.hasLettersOnly()) {
				position = str.stoi();

				for (int i = 0; i < ownedProps.getSize(); i++) {
					if (ownedProps[i]->getBoardIndex() == position) {
						propToSellOn = ownedProps[i];
						break;
					}
				}

				if (propToSellOn) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid property's position for selling!" << std::endl;
		}

		//if (propToBuildOn->getRentTierIndex() == 0) {
		//	std::cout << "You haven't collected all the properties of color " << (int)propToBuildOn->getColorSet() << std::endl;
		//	std::cout << "Please select an eligible property for building!" << std::endl;
		//}
		//if (propToSellOn->getRentTierIndex() == 0) {
		//	std::cout << propToSellOn->getName() << " doesn't have any builds! You are about to mortgage it for half the price!" << std::endl;
		//	continue;
		//}

		bool otherPropsReady = true;
		for (int i = 0; i < ownedProps.getSize(); i++) {
			if (ownedProps[i]->getColorSet() == propToSellOn->getColorSet()) {
				if (ownedProps[i]->getBuildsCount() > propToSellOn->getBuildsCount()) {
					otherPropsReady = false;
					break;
				}
			}
		}

		if (!otherPropsReady) {
			std::cout << "You have selected " << propToSellOn->getName() << " of color " << (int)propToSellOn->getColorSet() << " which has " << propToSellOn->getBuildsCount() << " buildings." << std::endl;
			std::cout << "But other properties of color " << (int)propToSellOn->getColorSet() << " have " << propToSellOn->getBuildsCount() + 1 << " buildings." << std::endl;
			std::cout << "Make sure all properties of the same color have the same amount of builds before selling some!" << std::endl;
			std::cout << "Try again by selecting an eligible property." << std::endl;
			continue;
		}

		if (propToSellOn->getRentTierIndex() == 0) {
			std::cout << propToSellOn->getName() << " doesn't have any builds! You are about to mortgage it for half the price!" << std::endl;
		}
		else {
			std::cout << propToSellOn->getName() << " has " << propToSellOn->getBuildsCount() << " buildings! You are about to sell one for half the price!" << std::endl;
		}

		bool isHouse = (propToSellOn->getBuildsCount() < 5);
		size_t priceToPay = isHouse ? propToSellOn->getHousePrice() / 2 : propToSellOn->getHotelPrice() / 2;
		MyString building = isHouse ? "house" : "hotel";

		std::cout << "Are you sure you want to sell a " << building << " for $" << priceToPay << " on " << propToSellOn->getName() << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldSell = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldSell = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldSell) {
			continue;
		}

		propToSellOn->decreaseRentTier();
		player.addMoney(priceToPay);
		std::cout << "You successfully sold a " << (isHouse ? "house" : "hotel") << " on " << propToSellOn->getName() << " which cost $" << priceToPay << std::endl;
		std::cout << "Its rent is now $" << propToSellOn->getRent() << std::endl;
	}
	std::cout << "You just finished selling! You can always come back as long as you are not in jail!" << std::endl;
}
