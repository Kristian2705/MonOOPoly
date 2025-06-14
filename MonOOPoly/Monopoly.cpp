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
	welcomePlayers();
	addPlayers();
	board->printBoard();
	//while (true) {
	//	Player& currentPlayer = board->getPlayer(currentPlayerIndex);
	//	std::cout << "Current Player: " << currentPlayer.getName() << std::endl;
	//	showPlayerData(currentPlayerIndex);
	//	std::cout << "Press Enter to roll the dice..." << std::endl;
	//	std::cin.get();
	//	int result = rollDice();
	//}
}

void Monopoly::welcomePlayers() const
{
	std::cout << "Welcome to MonOOPoly!" << std::endl;
	std::cout << "Press Enter to start the game..." << std::endl;
	std::cin.get();
}

int Monopoly::rollDice() const
{
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int total = die1 + die2;
	std::cout << "You rolled: " << die1 << " and " << die2 << " (Total: " << total << ")" << std::endl;
	return total;
}

void Monopoly::addPlayer(const Player& player)
{
	players.push_back(player);
}

const Player& Monopoly::getPlayer(int playerId) const
{
	for (int i = 0; i < players.getSize(); i++)
	{
		if (players[i].getId() == playerId)
		{
			return players[i];
		}
	}
	throw std::out_of_range("Player not found");
}

Player& Monopoly::getPlayer(int playerId)
{
	for (int i = 0; i < players.getSize(); i++)
	{
		if (players[i].getId() == playerId)
		{
			return players[i];
		}
	}
	throw std::out_of_range("Player not found");
}

const MyVector<Player>& Monopoly::getPlayers() const
{
	return players;
}

MyVector<Player>& Monopoly::getPlayers()
{
	return players;
}

void Monopoly::addPlayers()
{
	std::cout << "Enter the number of players (2-6): ";
	int numPlayers;
	std::cin >> numPlayers;
	while (numPlayers < 2 || numPlayers > GameConstants::MAX_PLAYERS) {
		std::cout << "Invalid number of players. Please enter a number between 2 and " << GameConstants::MAX_PLAYERS << "." << std::endl;
		std::cout << "Enter the number of players (2-6): ";
		std::cin >> numPlayers;
	}
	for (int i = 0; i < numPlayers; i++) {
		std::cout << "Enter name for Player " << (i + 1) << ": ";
		MyString name;
		std::cin >> name;
		Player player(name);
		addPlayer(player);
		std::cout << "Player " << (i + 1) << " added with ID: " << player.getId() << std::endl;
	}
}

void Monopoly::showPlayerData(int id) const
{
	const Player& player = getPlayer(id);
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
