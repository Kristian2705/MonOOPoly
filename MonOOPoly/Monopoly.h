#pragma once
#include "Board.h"

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
	int getNextPlayerIndex() const;
	Monopoly();
	~Monopoly();
public:
	static Monopoly* getInstance();
	static void freeInstance();
	void welcomePlayers();
	int rollDice();
	void stepOnCard();
	void showPlayerData(int id) const;
	void endTurn();
	void applyFieldEffect(size_t position);

	bool checkGameOver() const;
	bool getRolledStatus() const;
	bool getPairStatus() const;
	int getPairsCount() const;
	void resetPairStatus();
	const Player& getPlayerOnTurn() const;
	Player& getPlayerOnTurn();
	const Player& getPlayer(int playerId) const;
	Player& getPlayer(int playerId);
	const Player* getWinner() const;
	const MyVector<Player>& getPlayers() const;
	MyVector<Player>& getPlayers();
};

