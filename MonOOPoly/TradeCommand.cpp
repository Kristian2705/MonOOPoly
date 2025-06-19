#include "TradeCommand.h"

void TradeCommand::execute() const
{
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
		Player* receiver = nullptr;
		while (true)
		{
			char buffer[GameConstants::BUFFER_CAPACITY];
			std::cin >> buffer;
			MyString str(buffer);
			if (!str.hasLettersOnly()) {
				int command = str.stoi();
				if (command == 0) {
					shouldFinish = true;
					break;
				}

				for (int i = 0; i < validPlayers.getSize(); i++) {
					if (command == validPlayers[i]->getId()) {
						receiver = validPlayers[i];
						break;
					}
				}

				if (receiver) {
					break;
				}
			}
			std::cout << "Invalid input! Please enter a valid player index!" << std::endl;
		}

		if (shouldFinish) {
			break;
		}

		std::cout << "Are you sure you want to trade with " << receiver->getName() << " with index " << receiver->getId() << "?" << std::endl;
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
		std::cout << "You are now in a trade with " << receiver->getName() << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Here are his stats: " << std::endl;

		receiver->showInfo();

		std::cout << "Now you have to choose what you want from " << receiver->getName() << std::endl;
		std::cout << "1. Property" << std::endl;
		std::cout << "2. Station" << std::endl;
		std::cout << "3. Utility" << std::endl;
		std::cout << "4. Money" << std::endl;
		char buffer[GameConstants::BUFFER_CAPACITY];
		std::cin >> buffer;
		MyString str(buffer);
		if (!str.hasLettersOnly()) {
			int command = str.stoi();
			switch (command)
			{
			case 1:
				tradeProperty(receiver);
				break;
			case 2:
				tradeStation(receiver);
				break;
			case 3:
				tradeUtility(receiver);
				break;
			case 4:
				tradeMoney(receiver);
			default:
				std::cout << "Invalid command! Please try again!" << std::endl;
				break;
			}
		}
	}
}
