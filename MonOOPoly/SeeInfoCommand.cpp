#include "SeeInfoCommand.h"

void SeeInfoCommand::execute() const
{
	int index = 0;
	std::cout << "Please enter which player's info you'd like to see (1-" << game->getPlayers().getSize() << ")" << std::endl;
	char buffer[GameConstants::BUFFER_CAPACITY];
	std::cin >> buffer;
	while (true) {
		MyString str(buffer);
		if (!str.hasLettersOnly()) {
			index = str.stoi();
			break;
		}
		std::cout << "Invalid input. Please enter a number (1-" << game->getPlayers().getSize() << ")" << std::endl;
		std::cin >> buffer;
	}
	const Player& playerToShow = game->getPlayer(index);
	playerToShow.showInfo();
}
