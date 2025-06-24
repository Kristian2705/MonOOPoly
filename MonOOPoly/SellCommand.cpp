#include "SellCommand.h"

void SellCommand::execute() const
{
	int getPlayersInGameCount = game->getPlayersInGameCount();
	if (getPlayersInGameCount == 0) {
		throw std::invalid_argument("No game in progress. Please start a new game.");
	}

	Player& player = game->getPlayerOnTurn();

	//if (player.isInJail()) {
	//	throw std::invalid_argument("Get out of jail first and then try selling!");
	//}

	const MyVector<Property*>& ownedProps = player.getOwnedProperties();

	if (!ownedProps.getSize()) {
		throw std::invalid_argument("You don't have any properties yet so you can't sell buildings on them!");
	}

	MyVector<Property*> validPropsForBuilding;
	for (int i = 0; i < ownedProps.getSize(); i++) {
		int rentTierIndex = ownedProps[i]->getRentTierIndex();
		if (rentTierIndex >= GameConstants::FIRST_BUILDING_RENT_INDEX) {
			validPropsForBuilding.push_back(ownedProps[i]);
		}
	}

	if (!validPropsForBuilding.getSize()) {
		throw std::invalid_argument("You haven't built anything on your properties yet. You can mortgage them if you want.");
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
			if (str.isValidNumber()) {
				position = str.stoi();

				for (int i = 0; i < validPropsForBuilding.getSize(); i++) {
					if (validPropsForBuilding[i]->getBoardIndex() == position) {
						propToSellOn = validPropsForBuilding[i];
						break;
					}
				}

				if (propToSellOn) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid property's position for selling!" << std::endl;
		}

		if (propToSellOn->getRentTierIndex() == GameConstants::COLOR_SET_RENT_INDEX) {
			throw std::invalid_argument("This property is doesn't have any builds. You can mortgage it if you want.");
		}

		bool otherPropsReady = true;
		for (int i = 0; i < validPropsForBuilding.getSize(); i++) {
			if (validPropsForBuilding[i]->getColorSet() == propToSellOn->getColorSet()) {
				if (validPropsForBuilding[i]->getBuildsCount() > propToSellOn->getBuildsCount()) {
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

		std::cout << propToSellOn->getName() << " has " << propToSellOn->getBuildsCount() << " buildings! You are about to sell one for half the price!" << std::endl;

		bool isHouse = (propToSellOn->getBuildsCount() < GameConstants::HOTEL_BUILDING_NUM);
		size_t priceToPay = isHouse ? propToSellOn->getHousePrice() / GameConstants::HALF_PRICE_MULTIPLIER : propToSellOn->getHotelPrice() / GameConstants::HALF_PRICE_MULTIPLIER;
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
