#include "BuildCommand.h"

void BuildCommand::execute() const
{
	Player& player = game->getPlayerOnTurn();
	const MyVector<Property*>& ownedProps = player.getOwnedProperties();

	if (!ownedProps.getSize()) {
		throw std::invalid_argument("You don't have any properties to build on! Collect color sets and then build!");
	}

	MyVector<Property*> validPropsForBuilding;
	for (int i = 0; i < ownedProps.getSize(); i++) {
		int rentTierIndex = ownedProps[i]->getRentTierIndex();
		if (rentTierIndex >= 1 && rentTierIndex < 5) {
			validPropsForBuilding.push_back(ownedProps[i]);
		}
	}

	if (!validPropsForBuilding.getSize()) {
		throw std::invalid_argument("No eligible properties to build on! Collect color sets and then build");
	}

	std::cout << "Here are all the eligible properties for building!" << std::endl;
	for (int i = 0; i < validPropsForBuilding.getSize(); i++) {
		validPropsForBuilding[i]->showProperty();
		std::cout << std::endl;
	}

	while (true) {
		bool readyToBuild = true;
		while (true) {
			std::cout << "Ready to build? Type 'yes' or 'no'" << std::endl;
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				readyToBuild = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!readyToBuild) {
			break;
		}

		Property* propToBuildOn = nullptr;
		while (true) {
			std::cout << "You currently have $" << player.getMoney() << std::endl;
			std::cout << "Please enter the name of the property you'd like to build on!" << std::endl;
			//Maybe return indices
			MyString name;
			std::cin >> name;
			for (int i = 0; i < validPropsForBuilding.getSize(); i++) {
				if (name == validPropsForBuilding[i]->getName()) {
					propToBuildOn = validPropsForBuilding[i];
					break;
				}
			}
			//char buffer[GameConstants::BUFFER_CAPACITY];
			//std::cin >> buffer;
			//MyString str(buffer);
			//if (!str.hasLettersOnly()) {
			//	position = str.stoi();
			//	break;
			//}
			std::cout << "Invalid input! Please enter a valid property's name for building!" << std::endl;
		}
		if (propToBuildOn->getRentTierIndex() == 0) {
			std::cout << "You haven't collected all the properties of color " << (int)propToBuildOn->getColorSet() << std::endl;
			std::cout << "Please select an eligible property for building!" << std::endl;
		}
		else if (propToBuildOn->getRentTierIndex() == GameConstants::RENT_TIERS_COUNT - 1) {
			std::cout << "You have a hotel on " << propToBuildOn->getName() << "! You are stacked! Keep going!" << std::endl;
			std::cout << "Please select an eligible property for building!" << std::endl;
		}

		bool otherPropsReady = true;
		for (int i = 0; i < validPropsForBuilding.getSize(); i++) {
			if (validPropsForBuilding[i]->getColorSet() == propToBuildOn->getColorSet()) {
				if (validPropsForBuilding[i]->getBuildsCount() < propToBuildOn->getBuildsCount()) {
					otherPropsReady = false;
					break;
				}
			}
		}
		if (!otherPropsReady) {
			std::cout << "You have selected " << propToBuildOn->getName() << " of color " << (int)propToBuildOn->getColorSet() << " which has " << propToBuildOn->getBuildsCount() << std::endl;
			std::cout << "But other properties of color " << (int)propToBuildOn->getColorSet() << " have " << propToBuildOn->getBuildsCount() - 1 << std::endl;
			std::cout << "Make sure all properties of the same color have the same amount of builds before adding new!" << std::endl;
			std::cout << "Try again by selecting an eligible property." << std::endl;
			continue;
		}

		bool isHouse = (propToBuildOn->getBuildsCount() + 1) < 5;
		size_t priceToPay = isHouse ? propToBuildOn->getHousePrice() : propToBuildOn->getHotelPrice();
		MyString building = isHouse ? "house" : "hotel";

		std::cout << "Are you sure you want to build a " << building << " for $" << priceToPay << " on " << propToBuildOn->getName() << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldBuild = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldBuild = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldBuild) {
			continue;
		}

		if (player.getMoney() < priceToPay) {
			std::cout << "You don't have enough money to build on this property." << std::endl;
			std::cout << "Try building on cheaper properties or play more and collect money!" << std::endl;
			break;
		}
		propToBuildOn->increaseRentTier();
		player.addMoney((-1) * propToBuildOn->getRent());
		std::cout << "You successfully bought a " << (isHouse ? " house " : " hotel ") << " for " << propToBuildOn->getName() << " which cost $" << priceToPay << std::endl;
		std::cout << "Its rent is now $" << propToBuildOn->getRent() << std::endl;
		//std::cout << "Would you like to build more? Type 'yes' or 'no'" << std::endl;
		//MyString answer;
		//std::cin >> answer;
		//if (answer == "no") {
		//	break;
		//}
	}
	std::cout << "You just finished building! You can always come back as long as you are not in jail!" << std::endl;
}