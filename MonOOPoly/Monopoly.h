#pragma once
#include "Board.h"
#include "HelperFunctions.h"

class Monopoly
{
	bool isGameOver = false;
	int currentPlayerIndex;
	bool hasRolled = false;
	int pairsCount = 0;
	static Monopoly* instance;
	Board* board;
	CardDeck* deck;
	MyVector<Player> players;

	void addPlayers();
	void addPlayer(const Player& player);
	int getNextPlayerIndex();
	Monopoly();
	~Monopoly();
public:
	static Monopoly* getInstance();
	static void freeInstance();
	void welcomePlayers();
	void showMainMenu() const;
	void showMap() const;
	int rollDice();
	void stepOnCard();
	void endTurn();
	void applyFieldEffect(size_t position);

	int getPlayersInGameCount() const;
	bool checkGameOver() const;
	bool getRolledStatus() const;
	bool getPairStatus() const;
	int getPairsCount() const;
	int getPlayerMaxIndex() const;
	void resetPairStatus();
	const Player& getPlayerOnTurn() const;
	Player& getPlayerOnTurn();
	const Player& getPlayer(int playerId) const;
	Player& getPlayer(int playerId);
	const Player* getWinner() const;
	const MyVector<Player>& getPlayers() const;
	MyVector<Player>& getPlayers();
	void saveToBinaryFile() const;
	void loadFromBinaryFile();
	void truncateBinaryFiles() const;
};

