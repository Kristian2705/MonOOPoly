#include "TradeCommand.h"

void TradeCommand::tradeProperty(Player* player, Property*& property) const
{
	if (property) {
		std::cout << "You have already selected a property! Try selecting something else or move on to trading!" << std::endl;
		return;
	}

	MyVector<Property*> ownedProps = player->getOwnedProperties();

	if (!ownedProps.getSize()) {
		std::cout << "No properties in possession! Try selection something else or move on to trading!" << std::endl;
		return;
	}

	MyVector<Property*> validProps;

	for (int i = 0; i < ownedProps.getSize(); i++) {
		if (ownedProps[i]->getBuildsCount() == 0) {
			validProps.push_back(ownedProps[i]);
		}
	}

	if (!validProps.getSize()) {
		std::cout << "These properties have buildings on them! Only properties without buildings can be traded!" << std::endl;
		return;
	}

	std::cout << "Here are all the eligible properties for trading of " << player->getName() << ": " << std::endl;
	for (int i = 0; i < validProps.getSize(); i++) {
		validProps[i]->showProperty();
		std::cout << std::endl;
	}

	while (true)
	{
		int position = 0;
		while (true) {
			std::cout << "Please enter the position of the property: " << std::endl;

			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (str.isValidNumber()) {
				position = str.stoi();

				for (int i = 0; i < validProps.getSize(); i++) {
					if (validProps[i]->getBoardIndex() == position) {
						property = validProps[i];
						break;
					}
				}

				if (property) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid property's position for trading!" << std::endl;
		}

		std::cout << "Are you sure you want to select " << property->getName() << " with index " << property->getBoardIndex() << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldSelect = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldSelect = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldSelect) {
			property = nullptr;
			return;
		}

		bool otherPropsReady = true;
		for (int i = 0; i < ownedProps.getSize(); i++) {
			if ((property != ownedProps[i]) && (property->getColorSet() == ownedProps[i]->getColorSet())) {
				if (ownedProps[i]->getRentTierIndex() - 1 == GameConstants::COLOR_SET_RENT_INDEX) {
					otherPropsReady = false;
					break;
				}
				ownedProps[i]->decreaseRentTier();
			}
		}

		if (!otherPropsReady) {
			std::cout << "There are properties of this color that have buildings. Try selecting again!" << std::endl;
			continue;
		}

		std::cout << "You successfully selected " << property->getName() << "! You can now select something else." << std::endl;
		return;
	}

	property = nullptr;
}

void TradeCommand::tradeStation(Player* player, Station*& station) const
{
	if (station) {
		std::cout << "You have already selected a station! Try selecting something else or move on to trading!" << std::endl;
		return;
	}

	MyVector<Station*> ownedStations = player->getOwnedStations();

	if (!ownedStations.getSize()) {
		std::cout << "No stations in possession! Try selection something else or move on to trading!" << std::endl;
		return;
	}

	std::cout << "Here are all stations for trading of " << player->getName() << ": " << std::endl;
	for (int i = 0; i < ownedStations.getSize(); i++) {
		ownedStations[i]->showStation();
		std::cout << std::endl;
	}

	while (true)
	{
		int position = 0;
		while (true) {
			std::cout << "Please enter the position of the station: " << std::endl;

			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (str.isValidNumber()) {
				position = str.stoi();

				for (int i = 0; i < ownedStations.getSize(); i++) {
					if (ownedStations[i]->getBoardIndex() == position) {
						station = ownedStations[i];
						break;
					}
				}

				if (station) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid utility's position for trading!" << std::endl;
		}

		std::cout << "Are you sure you want to select " << station->getName() << " with index " << station->getBoardIndex() << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldSelect = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldSelect = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldSelect) {
			station = nullptr;
			return;
		}

		std::cout << "You successfully selected " << station->getName() << "! You can now select something else." << std::endl;
		return;
	}

	station = nullptr;
}

void TradeCommand::tradeUtility(Player* player, Utility*& utility) const
{
	if (utility) {
		std::cout << "You have already selected a utility! Try selecting something else or move on to trading!" << std::endl;
		return;
	}

	MyVector<Utility*> ownedUtilities = player->getUtilities();

	if (!ownedUtilities.getSize()) {
		std::cout << "No utility in possession! Try selection something else or move on to trading!" << std::endl;
		return;
	}

	std::cout << "Here are all utilities for trading of " << player->getName() << ": " << std::endl;
	for (int i = 0; i < ownedUtilities.getSize(); i++) {
		ownedUtilities[i]->showUtility();
		std::cout << std::endl;
	}

	while (true)
	{
		int position = 0;
		while (true) {
			std::cout << "Please enter the position of the utility: " << std::endl;

			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (str.isValidNumber()) {
				position = str.stoi();

				for (int i = 0; i < ownedUtilities.getSize(); i++) {
					if (ownedUtilities[i]->getBoardIndex() == position) {
						utility = ownedUtilities[i];
						break;
					}
				}

				if (utility) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid utility's position for trading!" << std::endl;
		}

		std::cout << "Are you sure you want to select " << utility->getName() << " with index " << utility->getBoardIndex() << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldSelect = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldSelect = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldSelect) {
			utility = nullptr;
			return;
		}

		std::cout << "You successfully selected " << utility->getName() << "! You can now select something else." << std::endl;
		return;
	}

	utility = nullptr;
}

void TradeCommand::tradeMoney(Player* player, int& amount) const
{
	while (true) {
		std::cout << "Please enter the amount of money: " << std::endl;

		char buffer[GameConstants::BUFFER_CAPACITY];
		std::cin >> buffer;
		MyString str(buffer);
		if (str.isValidNumber()) {
			amount = str.stoi();
			if (amount > player->getMoney()) {
				std::cout << "The selected amount of money is greater than the money in posession: $" << player->getMoney() << std::endl;
				continue;
			}
			std::cout << "You successfully selected an amount of $" << amount << std::endl;
			return;
		}
		std::cout << "Invalid input! Please enter a valid amount of money for trading!" << std::endl;
	}
}

void TradeCommand::showCurrentTrade() const
{
	trade->show();
}

void TradeCommand::clearTrade() const
{
	trade->clear();
}

TradeCommand::TradeCommand()
{
	trade = new Trade();
}

void TradeCommand::execute() const
{
	int getPlayersInGameCount = game->getPlayersInGameCount();
	if (getPlayersInGameCount == 0) {
		throw std::invalid_argument("No game in progress. Please start a new game.");
	}

	Player& playerOnTurn = game->getPlayerOnTurn();

	if (playerOnTurn.isInJail()) {
		throw std::invalid_argument("Get out of jail first and then try to trade with others!");
	}

	while (true)
	{
		std::cout << "-----------------------" << std::endl;
		std::cout << "This is the trade menu!" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "First you have to choose which player you want to trade with or go back!" << std::endl;
		std::cout << "Please enter the index of the player you want to trade with!" << std::endl;
		std::cout << "Here is a list with all eligible player for trade with their indices:" << std::endl;

		MyVector<Player>& players = game->getPlayers();
		MyVector<Player*> validPlayers;

		for (int i = 0; i < players.getSize(); i++) {
			if (!players[i].isInGame() || players[i].isInJail() || &players[i] == &playerOnTurn) {
				continue;
			}
			validPlayers.push_back(&players[i]);
			std::cout << players[i].getId() << ". " << players[i].getName() << std::endl;
		}

		std::cout << "0. To go back!" << std::endl;

		bool shouldFinish = false;
		trade->receiver = nullptr;
		trade->sender = &playerOnTurn;
		while (true)
		{
			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (str.isValidNumber()) {
				int command = str.stoi();
				if (command == 0) {
					shouldFinish = true;
					break;
				}

				for (int i = 0; i < validPlayers.getSize(); i++) {
					if (command == validPlayers[i]->getId()) {
						trade->receiver = validPlayers[i];
						break;
					}
				}

				if (trade->receiver) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid player index!" << std::endl;
		}

		if (shouldFinish) {
			break;
		}

		std::cout << "Are you sure you want to trade with " << trade->receiver->getName() << " with index " << trade->receiver->getId() << "?" << std::endl;
		std::cout << "Type 'yes' or 'no'" << std::endl;

		bool shouldTrade = true;
		while (true) {
			MyString answer;
			std::cin >> answer;
			if (answer == "no") {
				shouldTrade = false;
				break;
			}
			if (answer == "yes") {
				break;
			}
			std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
		}

		if (!shouldTrade) {
			continue;
		}

		std::cout << "--------------------------------------" << std::endl;
		std::cout << "You are now in a trade with " << trade->receiver->getName() << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Here are his stats: " << std::endl;

		trade->receiver->showInfo();

		while (true)
		{
			std::cout << std::endl;
			std::cout << "You have to choose what you want from " << trade->receiver->getName() << std::endl;
			std::cout << "1. Property" << std::endl;
			std::cout << "2. Station" << std::endl;
			std::cout << "3. Utility" << std::endl;
			std::cout << "4. Money" << std::endl;
			std::cout << "If you want to see the current trade window type '5'" << std::endl;
			std::cout << "When you are ready type '6' to select what you will offer." << std::endl;
			std::cout << "If you want to cancel the trade window type '0'." << std::endl;
			
			bool moveToNextStep = false;
			bool shouldCancel = false;
			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (str.isValidNumber()) {
				int command = str.stoi();
				switch (command)
				{
				case 0:
					shouldCancel = true;
					break;
				case 1:
					tradeProperty(trade->receiver, trade->propertyToGet);
					break;
				case 2:
					tradeStation(trade->receiver, trade->stationToGet);
					break;
				case 3:
					tradeUtility(trade->receiver, trade->utilityToGet);
					break;
				case 4:
					tradeMoney(trade->receiver, trade->moneyToGet);
					break;
				case 5:
					showCurrentTrade();
					break;
				case 6:
					moveToNextStep = true;
					break;
				default:
					std::cout << "Invalid command! Please try again!" << std::endl;
					break;
				}
			}

			if (shouldCancel) {
				//'yes/no' confirmation to add
				std::cout << "You canceled the trade window with " << trade->receiver->getName() << std::endl;
				clearTrade();
				break;
			}

			if (!moveToNextStep) {
				continue;
			}

			while (true)
			{
				std::cout << std::endl;
				std::cout << "You have to choose what you will offer " << trade->receiver->getName() << std::endl;
				std::cout << "1. Property" << std::endl;
				std::cout << "2. Station" << std::endl;
				std::cout << "3. Utility" << std::endl;
				std::cout << "4. Money" << std::endl;
				std::cout << "If you want to see the current trade window type '5'" << std::endl;
				std::cout << "When you are ready type '6' to initiate the trade." << std::endl;
				std::cout << "If you want to go back type '0'." << std::endl;

				moveToNextStep = false;
				bool shouldGoBack = false;
				char buffer[GameConstants::BUFFER_CAPACITY];
				std::cin >> buffer;
				MyString str(buffer);
				if (str.isValidNumber()) {
					int command = str.stoi();
					switch (command)
					{
					case 0:
						shouldGoBack = true;
						break;
					case 1:
						tradeProperty(trade->sender, trade->propertyToGive);
						break;
					case 2:
						tradeStation(trade->sender, trade->stationToGive);
						break;
					case 3:
						tradeUtility(trade->sender, trade->utilityToGive);
						break;
					case 4:
						tradeMoney(trade->sender, trade->moneyToGive);
						break;
					case 5:
						showCurrentTrade();
						break;
					case 6:
						moveToNextStep = true;
						break;
					default:
						std::cout << "Invalid command! Please try again!" << std::endl;
						break;
					}
				}

				if (shouldGoBack) {
					//'yes/no' confirmation to add
					std::cout << "You went back! Select what you want to get from " << trade->receiver->getName() << std::endl;
					break;
				}

				if (!moveToNextStep) {
					continue;
				}

				std::cout << std::endl;
				std::cout << "Here is the final look of the trade: " << std::endl;
				std::cout << std::endl;
				showCurrentTrade();

				std::cout << std::endl;
				std::cout << "Are you sure you want to send it to " << trade->receiver->getName() << std::endl;
				std::cout << "Please type 'yes' or 'no'" << std::endl;

				bool shouldSend = true;
				while (true) {
					MyString answer;
					std::cin >> answer;
					if (answer == "no") {
						shouldSend = false;
						break;
					}
					if (answer == "yes") {
						break;
					}
					std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
				}

				if (!shouldSend) {
					std::cout << "You have been send to the previous tab! Edit what you need!" << std::endl;
					continue;
				}

				std::cout << "Trade sent successfully to " << trade->receiver->getName() << "!" << std::endl;

				std::cout << "Now its up to you " << trade->receiver->getName() << "!" << std::endl;

				std::cout << std::endl;
				std::cout << "Here is the final look of the trade: " << std::endl;
				std::cout << std::endl;
				showCurrentTrade();

				std::cout << std::endl;
				std::cout << "Do you accept the trade of " << trade->sender->getName() << std::endl;
				std::cout << "Please type 'yes' or 'no'" << std::endl;

				bool isAccepted = true;
				while (true) {
					MyString answer;
					std::cin >> answer;
					if (answer == "no") {
						isAccepted = false;
						break;
					}
					if (answer == "yes") {
						break;
					}
					std::cout << "Invalid input. Please type 'yes' or 'no'" << std::endl;
				}

				if (!isAccepted) {
					std::cout << "Trade declined!" << std::endl;
					return;
				}

				trade->initiate();
				std::cout << "Trade accepted successfully!" << std::endl;
				return;
			}
		}
	}

	std::cout << "You successfully exited the trading menu!" << std::endl;
}

TradeCommand::~TradeCommand()
{
	delete trade;
}
