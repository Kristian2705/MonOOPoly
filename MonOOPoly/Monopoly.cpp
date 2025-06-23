#include "Monopoly.h"

int Monopoly::getNextPlayerIndex() const
{
	if(currentPlayerIndex >= players.getSize())
	{
		return GameConstants::FIRST_PLAYER_ID;
	}

	for(int i = currentPlayerIndex; i < players.getSize(); i++)
	{
		if (players[i].isInGame())
		{
			return players[i].getId();
		}
	}
}

Monopoly::Monopoly() : currentPlayerIndex(GameConstants::FIRST_PLAYER_ID)
{
	board = Board::getInstance();
	deck = CardDeck::getInstance();
}

Monopoly::~Monopoly()
{
	board->freeInstance();
	deck->freeInstance();
}

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

void Monopoly::welcomePlayers()
{
	std::cout << "Welcome to MonOOPoly!" << std::endl;
	std::cout << "Press anything to start the game..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	addPlayers();
}

int Monopoly::rollDice()
{
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int total = die1 + die2;
	if (die1 == die2) {
		pairsCount++;
	}
	else {
		pairsCount = 0;
	}
	std::cout << "You rolled: " << die1 << " and " << die2 << " (Total: " << total << ")" << std::endl;
	hasRolled = true;
	if (pairsCount == 3) {
		std::cout << "You have been caught for speeding!" << std::endl;
		Player& playerOnTurn = getPlayerOnTurn();
		playerOnTurn.setJailStatus();
		playerOnTurn.moveTo(GameConstants::JAIL_FIELD_INDEX);
		pairsCount = 0;
		throw std::invalid_argument("You have been sent to jail! Next turn you can pay $50 and play or wait for 3 turns.");
	}
	return total;
}

void Monopoly::stepOnCard()
{
	Player& cP = getPlayer(currentPlayerIndex);
	Card* card = deck->drawCard();
	card->applyEffect(cP);
}

bool Monopoly::checkGameOver() const
{
	int playersInGame = 0;
	for (int i = 0; i < players.getSize(); i++)
	{
		if (players[i].isInGame())
		{
			playersInGame++;
		}
	}
	return playersInGame <= 1;
}

bool Monopoly::getRolledStatus() const
{
	return hasRolled;
}

bool Monopoly::getPairStatus() const
{
	return pairsCount != 0;
}

int Monopoly::getPairsCount() const
{
	return pairsCount;
}

void Monopoly::resetPairStatus()
{
	pairsCount = 0;
}


const Player& Monopoly::getPlayerOnTurn() const
{
	return players[currentPlayerIndex - 1];
}

Player& Monopoly::getPlayerOnTurn()
{
	return players[currentPlayerIndex - 1];
}

void Monopoly::addPlayer(const Player& player)
{
	players.push_back(player);
}

const Player& Monopoly::getPlayer(int playerId) const
{
	if (playerId < 1 || playerId > players.getSize()) {
		throw std::out_of_range("Player not found");
	}
	return players[playerId - 1];
}

Player& Monopoly::getPlayer(int playerId)
{
	if (playerId < 1 || playerId > players.getSize()) {
		throw std::out_of_range("Player not found");
	}
	return players[playerId - 1];
}

const Player* Monopoly::getWinner() const  
{  
	for (int i = 0; i < players.getSize(); i++)  
	{  
		if (players[i].isInGame())  
		{  
			return &players[i];
		}  
	}  
	return nullptr; // No winner found  
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
	std::cout << numPlayers << " added successfully!" << std::endl;
	std::cout << "Are you ready to play?" << std::endl;
	std::cout << "Press enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	board->printBoard();
	std::cout << "Player " << currentPlayerIndex << "'s turn." << std::endl;
	std::cout << "Type help in order to see all the options" << std::endl;
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

void Monopoly::endTurn()
{
	currentPlayerIndex = getNextPlayerIndex();
	//currentPlayerIndex = (currentPlayerIndex++) % players.getSize();
	//while (!players[currentPlayerIndex - 1].isInGame())
	//{
	//	currentPlayerIndex = (currentPlayerIndex++) % players.getSize();
	//}
	pairsCount = 0;
	hasRolled = false;
	std::cout << "Player " << currentPlayerIndex << "'s turn." << std::endl;
}

void Monopoly::applyFieldEffect(size_t position)
{
	board->stepOn(position, getPlayerOnTurn());
}

//void Monopoly::nextTurn()
//{
//	currentPlayerIndex++;
//	if (currentPlayerIndex >= GameConstants::MAX_PLAYERS)
//	{
//		currentPlayerIndex = GameConstants::FIRST_PLAYER_ID;
//	}
//}
