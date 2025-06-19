#include "HelpCommand.h"

void HelpCommand::execute() const
{
	std::cout << "Here is a list of commands during each phase of the game: " << std::endl;

	std::cout << "---------------------------------------------" << std::endl;

	std::cout << "During player's turn: " << std::endl;
	std::cout << "1. 'roll_dice' to roll the dice" << std::endl;
	std::cout << "2. 'build' to build houses or hotels on your properties" << std::endl;
	std::cout << "3. 'sell' to sell houses or hotels on your properties when you need money" << std::endl;
	std::cout << "4. 'mortgage' to mortgage a property, station or utility when you need money" << std::endl;
	std::cout << "5. 'see_info' to see the data of a player by index" << std::endl;
	std::cout << "6. 'see_map' to see the map" << std::endl;

	std::cout << "---------------------------------------------" << std::endl;

	std::cout << "After rolling the dice and the field has applied its effect: " << std::endl;
	std::cout << "1. 'end_turn/roll_dice' to end the turn or to roll again after getting a pair" << std::endl;
	std::cout << "2. 'build' to build houses or hotels on your properties" << std::endl;
	std::cout << "3. 'sell' to sell houses or hotels on your properties when you need money" << std::endl;
	std::cout << "4. 'mortgage' to mortgage a property, station or utility when you need money" << std::endl;
	std::cout << "5. 'see_info' to see the data of a player by index" << std::endl;
	std::cout << "6. 'see_map' to see the map" << std::endl;
	std::cout << "7. 'trade' to initiate a trade" << std::endl;
	std::cout << "8. 'bankrupt' to surrender" << std::endl;

	std::cout << "---------------------------------------------" << std::endl;

	std::cout << "In jail: " << std::endl;
	std::cout << "1. 'roll_dice' to roll the dice" << std::endl;
	std::cout << "2. 'pay_release' to pay $50 to get released" << std::endl;
	std::cout << "3. 'use_card' to get a free release from jail" << std::endl;
	std::cout << "4. 'see_info' to see the data of a player by index" << std::endl;
	std::cout << "5. 'see_map' to see the map" << std::endl;
	std::cout << "IMPORTANT: You can pay $50 even after rolling the dice on the same turn!" << std::endl;

	std::cout << "---------------------------------------------" << std::endl;

	std::cout << "If you don't have money to pay for a rent or something else: " << std::endl;
	std::cout << "1. 'sell' to sell houses or hotels on your properties when you need money" << std::endl;
	std::cout << "2. 'mortgage' to mortgage a property, station or utility when you need money" << std::endl;
	std::cout << "3. 'see_info' to see the data of a player by index" << std::endl;
	std::cout << "4. 'see_map' to see the map" << std::endl;
	std::cout << "5. 'trade' to initiate a trade" << std::endl;
	std::cout << "6. 'bankrupt' to surrender" << std::endl;

	std::cout << "---------------------------------------------" << std::endl;

	//std::cout << "If you have selected an option and want to go back, type 'back'" << std::endl;
}