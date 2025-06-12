#include "Monopoly.h"

Monopoly::Monopoly() : currentPlayerIndex(GameConstants::FIRST_PLAYER_ID), board(nullptr) { }

Monopoly* Monopoly::instance = nullptr;

Monopoly* Monopoly::getInstance()
{
	if (!instance)
	{
		instance = new Monopoly();
	}

	return instance;
}

void Monopoly::freeInstance()
{
	delete instance;
	instance = nullptr;
}

void Monopoly::startGame()
{
	board = Board::getInstance();


	
	while (true) {
		Player& currentPlayer = board->getPlayer(currentPlayerIndex);
		std::cout << "Current Player: " << currentPlayer.getName() << std::endl;
		showPlayerData(currentPlayerIndex);
		std::cout << "Press Enter to roll the dice..." << std::endl;
		std::cin.get();
		int result = rollDice();
	}
}

int Monopoly::rollDice() const
{
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int total = die1 + die2;
	std::cout << "You rolled: " << die1 << " and " << die2 << " (Total: " << total << ")" << std::endl;
	return total;
}

void Monopoly::showPlayerData(int id) const
{
	const Player& player = board->getPlayer(id);
	std::cout << "Player ID: " << player.getId() << std::endl
		<< "Name: " << player.getName() << std::endl
		<< "Money: " << player.getMoney() << std::endl
		<< "Total Balance: " << player.getTotalBalance() << std::endl
		<< "Position: " << player.getCurrentPosition() << std::endl
		<< "In Jail: " << (player.isInJail() ? "Yes" : "No") << std::endl;
}

//void Monopoly::nextTurn()
//{
//	currentPlayerIndex++;
//	if (currentPlayerIndex >= GameConstants::MAX_PLAYERS)
//	{
//		currentPlayerIndex = GameConstants::FIRST_PLAYER_ID;
//	}
//}
