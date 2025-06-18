#include "MortgageCommand.h"

void MortgageCommand::mortgageProperty()
{
	Player& player = game->getPlayerOnTurn();
	const MyVector<Property*>& ownedProps = player.getOwnedProperties();

	if (!ownedProps.getSize()) {
		std::cout << "You don't have any properties yet so you can't mortgage them!" << std::endl;
		return;
	}

	MyVector<Property*> validPropsForBuilding;
	for (int i = 0; i < ownedProps.getSize(); i++) {
		int rentTierIndex = ownedProps[i]->getRentTierIndex();
		if (rentTierIndex <= GameConstants::COLOR_SET_RENT_INDEX) {
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

		propToMortgage->mortgage();
		player.addMoney(rewardForMortgage);


		//Color set check

		std::cout << "You successfully mortgaged " << propToMortgage->getName() << " for $" << rewardForMortgage << std::endl;
		std::cout << propToMortgage->getName() << " is now owned by the bank. Whoever steps on it may buy it or skip it." << std::endl;
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
			case 2:
			case 3:
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
