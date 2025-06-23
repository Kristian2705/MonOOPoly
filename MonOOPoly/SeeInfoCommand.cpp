#include "SeeInfoCommand.h"

void SeeInfoCommand::execute() const
{
	int getPlayersInGameCount = game->getPlayersInGameCount();
	if (getPlayersInGameCount == 0) {
		throw std::invalid_argument("No game in progress. Please start a new game.");
	}

	int index = 0;
	std::cout << "Please enter which player's info you'd like to see by index" << std::endl;
	for(int i = 0; i < game->getPlayers().getSize(); i++) {
		std::cout << i + 1 << ". " << game->getPlayer(i + 1).getName() << std::endl;
	}
	char buffer[GameConstants::BUFFER_CAPACITY];
	std::cin >> buffer;
	while (true) {
		MyString str(buffer);
		if (str.isValidNumber()) {
			index = str.stoi();
			break;
		}
		std::cout << "Invalid input. Please enter a number (1-" << game->getPlayers().getSize() << ")" << std::endl;
		std::cin >> buffer;
	}
	const Player& playerToShow = game->getPlayer(index);
	playerToShow.showInfo();
}
