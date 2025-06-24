#include "Monopoly.h"

int Monopoly::getNextPlayerIndex()
{
	while (true)
	{
		if (currentPlayerIndex >= getPlayerMaxIndex()) {
			currentPlayerIndex = 0;
		}
		if(players[currentPlayerIndex].isInGame())
		{
			return players[currentPlayerIndex].getId();
		}
		currentPlayerIndex++;
	}
}

Monopoly::Monopoly() : currentPlayerIndex(GameConstants::INVALID_PLAYER_ID)
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
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "        You started a new game!      " << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Press anything to start the game..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	addPlayers();
}

void Monopoly::showMainMenu() const
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "         Welcome to MonOOPoly!        " << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Please choose an option: " << std::endl;
	std::cout << "1. 'help' to see the available commands in game" << std::endl;
	std::cout << "2. 'new_game' to start a new game" << std::endl;
	std::cout << "3. 'save_game' to save your game and exit" << std::endl;
	std::cout << "4. 'load_game' to load the latest saved game" << std::endl;
	std::cout << "5. 'exit' to exit the game without saving" << std::endl;
}

void Monopoly::showMap() const
{
	board->printBoard();
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

int Monopoly::getPlayersInGameCount() const
{
	int playersInGame = 0;
	for(int i = 0; i < players.getSize(); i++)
	{
		if (players[i].isInGame())
		{
			playersInGame++;
		}
	}
	return playersInGame;
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

int Monopoly::getPlayerMaxIndex() const
{
	int maxIndex = 0;
	for(int i = 0; i < players.getSize(); i++)
	{
		if (players[i].getId() > maxIndex)
		{
			maxIndex = players[i].getId();
		}
	}
	return maxIndex;
}

void Monopoly::resetPairStatus()
{
	pairsCount = 0;
}


const Player& Monopoly::getPlayerOnTurn() const
{
	for(int i = 0; i < players.getSize(); i++)
	{
		if (players[i].getId() == currentPlayerIndex)
		{
			return players[i];
		}
	}
}

Player& Monopoly::getPlayerOnTurn()
{
	for (int i = 0; i < players.getSize(); i++)
	{
		if (players[i].getId() == currentPlayerIndex)
		{
			return players[i];
		}
	}
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

const Player* Monopoly::getWinner() const  
{  
	for (int i = 0; i < players.getSize(); i++)  
	{  
		if (players[i].isInGame())  
		{  
			return &players[i];
		}  
	}  
	return nullptr;
}

const MyVector<Player>& Monopoly::getPlayers() const
{
	return players;
}

MyVector<Player>& Monopoly::getPlayers()
{
	return players;
}

void Monopoly::saveToBinaryFile() const
{
	std::ofstream ofs("monopoly_game.dat", std::ios::binary | std::ios::trunc);
	if (!ofs) {
		std::cerr << "Error opening file for saving." << std::endl;
		return;
	}

	int playerCount = players.getSize();
	ofs.write((const char*)(&playerCount), sizeof(playerCount));

	std::ofstream playersOfs("players.dat", std::ios::binary | std::ios::trunc);
	for (int i = 0; i < playerCount; i++) {
		players[i].saveToBinary(playersOfs);
	}
	playersOfs.close();

	ofs.write((const char*)(&currentPlayerIndex), sizeof(currentPlayerIndex));
	ofs.write((const char*)(&hasRolled), sizeof(hasRolled));
	ofs.write((const char*)(&pairsCount), sizeof(pairsCount));

	std::ofstream fieldsOfs("fields.dat", std::ios::binary | std::ios::trunc);
	board->saveToBinary(fieldsOfs);
	fieldsOfs.close();

	ofs.close();
	throw std::overflow_error("Game saved successfully!");
}

void Monopoly::loadFromBinaryFile()
{
	std::ifstream ifs("monopoly_game.dat", std::ios::binary);

	if (!ifs) {
		throw std::invalid_argument("No game saved. Please start a new one!");
	}

	if(HelperFunctions::getFileSize(ifs) == 0)
	{
		throw std::invalid_argument("No game saved. Please start a new one!");
	}

	int playerCount;
	ifs.read((char*)(&playerCount), sizeof(playerCount));

	std::ifstream playersIfs("players.dat", std::ios::binary);
	for (int i = 0; i < playerCount; i++) {
		Player player;
		player.loadFromBinary(playersIfs);
		addPlayer(player);
	}
	playersIfs.close();

	ifs.read((char*)(&currentPlayerIndex), sizeof(currentPlayerIndex));
	ifs.read((char*)(&hasRolled), sizeof(hasRolled));
	ifs.read((char*)(&pairsCount), sizeof(pairsCount));

	std::ifstream fieldsIfs("fields.dat", std::ios::binary);
	board->loadFromBinary(fieldsIfs);
	fieldsIfs.close();

	ifs.close();

	std::cout << "Game loaded successfully!" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Player " << currentPlayerIndex << "'s turn." << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void Monopoly::truncateBinaryFiles() const
{
	std::ofstream ofs("monopoly_game.dat", std::ios::trunc | std::ios::binary);
	if (!ofs) {
		std::cerr << "Error opening game save file for truncation." << std::endl;
		return;
	}
	ofs.close();
	std::ofstream playersOfs("players.dat", std::ios::trunc | std::ios::binary);
	if (!playersOfs) {
		std::cerr << "Error opening players save file for truncation." << std::endl;
		return;
	}
	playersOfs.close();
	std::ofstream fieldsOfs("fields.dat", std::ios::trunc | std::ios::binary);
	if (!fieldsOfs) {
		std::cerr << "Error opening fields save file for truncation." << std::endl;
		return;
	}
	fieldsOfs.close();
}

void Monopoly::addPlayers()
{
	std::cout << "Enter the number of players (2-6): ";
	int numPlayers = 0;
	while (true)
	{
		char buffer[GameConstants::BUFFER_CAPACITY];
		std::cin >> buffer;
		MyString str(buffer);
		if(str.isValidNumber()) {
			numPlayers = str.stoi();
			if (numPlayers < 2 || numPlayers > GameConstants::MAX_PLAYERS) 
			{
				std::cout << "Invalid number of players. Please enter a number between 2 and " << GameConstants::MAX_PLAYERS << "." << std::endl;
				std::cout << "Enter the number of players (2-6): ";
				continue;
			}
			else {
				break;
			}
		}
		std::cout << "Invalid input! Please enter a valid number of players (2-6): ";
	}

	for (int i = 0; i < numPlayers; i++) {
		std::cout << "Enter name for Player " << (i + 1) << ": ";
		MyString name;
		std::cin >> name;
		Player player(name);
		addPlayer(player);
		std::cout << "Player " << name << " added with ID: " << player.getId() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;
	std::cout << numPlayers << " players added successfully!" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	currentPlayerIndex = players[0].getId();

	std::cout << "Are you ready to play?" << std::endl;
	std::cout << "Press enter to continue..." << std::endl;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	board->printBoard();

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Player " << currentPlayerIndex << "'s turn." << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void Monopoly::endTurn()
{
	currentPlayerIndex = getNextPlayerIndex();
	pairsCount = 0;
	hasRolled = false;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Player " << currentPlayerIndex << "'s turn." << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void Monopoly::applyFieldEffect(size_t position)
{
	board->stepOn(position, getPlayerOnTurn());
}
