#include "MortgageCommand.h"

void MortgageCommand::mortgageProperty()
{
	Player& player = game->getPlayerOnTurn();
	const MyVector<Property*>& ownedProps = player.getOwnedProperties();

	if (!ownedProps.getSize()) {
		std::cout << "You don't have any properties yet so you can't mortgage them!" << std::endl;
		return;
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
