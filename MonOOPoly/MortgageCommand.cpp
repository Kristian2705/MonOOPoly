#include "MortgageCommand.h"

void MortgageCommand::mortgageProperty() const
{
	Player& player = game->getPlayerOnTurn();
	const MyVector<Property*>& ownedProps = player.getOwnedProperties();

	if (!ownedProps.getSize()) {
		std::cout << "You don't have any properties yet so you can't mortgage them!" << std::endl;
		return;
	}

	MyVector<Property*> validPropsForBuilding;
	for (int i = 0; i < ownedProps.getSize(); i++) {
		if (ownedProps[i]->getBuildsCount() == 0) {
			validPropsForBuilding.push_back(ownedProps[i]);
		}
	}

	if (!validPropsForBuilding.getSize()) {
		std::cout << "Your properties have buildings on them! Make sure to sell them before mortgaging!" << std::endl;
		return;
	}

	std::cout << "Here are all the eligible properties for mortgaging!" << std::endl;
	for (int i = 0; i < validPropsForBuilding.getSize(); i++) {
		validPropsForBuilding[i]->showProperty();
		std::cout << std::endl;
	}

	while (true) {
		bool readyToMortgage = true;
		while (true) {
			std::cout << "Ready to mortgage a property? Type 'yes' or 'no'" << std::endl;
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				readyToMortgage = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}
		
		if (!readyToMortgage) {
			break;
		}

		Property* propToMortgage = nullptr;
		int position = 0;
		while (true) {
			std::cout << "You currently have $" << player.getMoney() << std::endl;
			std::cout << "Please enter the position of the property you'd like to mortgage!" << std::endl;

			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (!str.hasLettersOnly()) {
				position = str.stoi();

				for (int i = 0; i < validPropsForBuilding.getSize(); i++) {
					if (validPropsForBuilding[i]->getBoardIndex() == position) {
						propToMortgage = validPropsForBuilding[i];
						break;
					}
				}

				if (propToMortgage) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid property's position for mortgaging!" << std::endl;
		}

		if (!propToMortgage->getOwner()) {
			std::cout << "You already mortgaged " << propToMortgage->getName() << std::endl;
			std::cout << "Please select an eligible property for mortgaging!" << std::endl;
			continue;
		}

		size_t rewardForMortgage = propToMortgage->getPrice() / GameConstants::HALF_PRICE_MULTIPLIER;
		std::cout << "Are you sure you want to mortgage " << propToMortgage->getName() << " for $" << rewardForMortgage << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldMortgage = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldMortgage = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldMortgage) {
			continue;
		}

		bool otherPropsReady = true;
		for (int i = 0; i < ownedProps.getSize(); i++) {
			if ((propToMortgage != ownedProps[i]) && (propToMortgage->getColorSet() == ownedProps[i]->getColorSet())) {
				if (ownedProps[i]->getRentTierIndex() - 1 == GameConstants::COLOR_SET_RENT_INDEX) {
					otherPropsReady = false;
					break;
				}
				//might add a check: ownedProps[i]->getRentTierIndex() == 0
				ownedProps[i]->decreaseRentTier();
			}
		}

		if (!otherPropsReady) {
			std::cout << "You have properties of this color that have buildings. Make sure to sell everything on your color set before mortgaging!" << std::endl;
			continue;
		}

		propToMortgage->mortgage();
		player.addMoney(rewardForMortgage);

		std::cout << "You successfully mortgaged " << propToMortgage->getName() << " for $" << rewardForMortgage << std::endl;
		std::cout << propToMortgage->getName() << " is now owned by the bank. Whoever steps on it may buy it or skip it." << std::endl;
	}
}

void MortgageCommand::mortgageStation() const
{
	Player& player = game->getPlayerOnTurn();
	const MyVector<Station*>& ownedStations = player.getOwnedStations();

	if (!ownedStations.getSize()) {
		std::cout << "You don't have any stations yet so you can't mortgage them!" << std::endl;
		return;
	}

	std::cout << "Here are your stations!" << std::endl;
	for (int i = 0; i < ownedStations.getSize(); i++) {
		ownedStations[i]->showStation();
		std::cout << std::endl;
	}

	while (true)
	{
		if (!ownedStations.getSize()) {
			std::cout << "You currently don't have any stations so you can't mortgage them!" << std::endl;
			break;
		}

		bool readyToMortgage = true;
		while (true) {
			std::cout << "Ready to mortgage a stations? Type 'yes' or 'no'" << std::endl;
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				readyToMortgage = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!readyToMortgage) {
			break;
		}

		Station* stationToMortgage = nullptr;
		int position = 0;
		while (true) {
			std::cout << "You currently have $" << player.getMoney() << std::endl;
			std::cout << "Please enter the position of the station you'd like to mortgage!" << std::endl;

			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (!str.hasLettersOnly()) {
				position = str.stoi();

				for (int i = 0; i < ownedStations.getSize(); i++) {
					if (ownedStations[i]->getBoardIndex() == position) {
						stationToMortgage = ownedStations[i];
						break;
					}
				}

				if (stationToMortgage) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid property's position for mortgaging!" << std::endl;
		}

		size_t rewardForMortgage = stationToMortgage->getPrice() / GameConstants::HALF_PRICE_MULTIPLIER;
		std::cout << "Are you sure you want to mortgage " << stationToMortgage->getName() << " for $" << rewardForMortgage << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldMortgage = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldMortgage = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldMortgage) {
			continue;
		}

		stationToMortgage->mortgage();
		player.addMoney(rewardForMortgage);

		for (int i = 0; i < ownedStations.getSize(); i++) {
			ownedStations[i]->decreaseRentTier();
		}

		std::cout << "You successfully mortgaged " << stationToMortgage->getName() << " for $" << rewardForMortgage << std::endl;
		std::cout << stationToMortgage->getName() << " is now owned by the bank. Whoever steps on it may buy it or skip it." << std::endl;
	}
}

void MortgageCommand::mortgageUtility() const
{
	Player& player = game->getPlayerOnTurn();
	const MyVector<Utility*>& ownedUtilities = player.getUtilities();

	if (!ownedUtilities.getSize()) {
		std::cout << "You don't have any utilities yet so you can't mortgage them!" << std::endl;
		return;
	}

	std::cout << "Here are your utilities!" << std::endl;
	for (int i = 0; i < ownedUtilities.getSize(); i++) {
		ownedUtilities[i]->showUtility();
		std::cout << std::endl;
	}

	while (true)
	{
		if (!ownedUtilities.getSize()) {
			std::cout << "You currently don't have any utilities so you can't mortgage them!" << std::endl;
			break;
		}

		bool readyToMortgage = true;
		while (true) {
			std::cout << "Ready to mortgage a utility? Type 'yes' or 'no'" << std::endl;
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				readyToMortgage = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!readyToMortgage) {
			break;
		}

		Utility* utilityToMortage = nullptr;
		int position = 0;
		while (true) {
			std::cout << "You currently have $" << player.getMoney() << std::endl;
			std::cout << "Please enter the position of the utility you'd like to mortgage!" << std::endl;

			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (!str.hasLettersOnly()) {
				position = str.stoi();

				for (int i = 0; i < ownedUtilities.getSize(); i++) {
					if (ownedUtilities[i]->getBoardIndex() == position) {
						utilityToMortage = ownedUtilities[i];
						break;
					}
				}

				if (utilityToMortage) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid property's position for mortgaging!" << std::endl;
		}

		size_t rewardForMortgage = utilityToMortage->getPrice() / GameConstants::HALF_PRICE_MULTIPLIER;
		std::cout << "Are you sure you want to mortgage " << utilityToMortage->getName() << " for $" << rewardForMortgage << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldMortgage = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldMortgage = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldMortgage) {
			continue;
		}

		utilityToMortage->mortgage();
		player.addMoney(rewardForMortgage);

		for (int i = 0; i < ownedUtilities.getSize(); i++) {
			ownedUtilities[i]->decreaseRentMultiplier();
		}

		std::cout << "You successfully mortgaged " << utilityToMortage->getName() << " for $" << rewardForMortgage << std::endl;
		std::cout << utilityToMortage->getName() << " is now owned by the bank. Whoever steps on it may buy it or skip it." << std::endl;
	}
}

void MortgageCommand::execute() const
{
	Player& player = game->getPlayerOnTurn();

	if (player.isInJail()) {
		throw std::invalid_argument("Get out of jail first and then try mortgaging!");
	}

	while (true) {
		std::cout << "Here is a list of the things you can mortgage. Enter a number based on the field you want to sell: " << std::endl;
		std::cout << "1. Property" << std::endl;
		std::cout << "2. Station" << std::endl;
		std::cout << "3. Utility" << std::endl;
		std::cout << "4. Type if you want to exit this menu." << std::endl;
		char buffer[GameConstants::BUFFER_CAPACITY];
		std::cin >> buffer;
		MyString str(buffer);
		if (!str.hasLettersOnly()) {
			int command = str.stoi();
			switch (command)
			{
			case 1:
				mortgageProperty();
				break;
			case 2:
				mortgageStation();
				break;
			case 3:
				mortgageUtility();
				break;
			case 4:
				std::cout << "You successfully exited the 'mortgage' menu!" << std::endl;
				return;
			default:
				std::cout << "Invalid command! Please try again!" << std::endl;
				break;
			}
		}
	}
}
