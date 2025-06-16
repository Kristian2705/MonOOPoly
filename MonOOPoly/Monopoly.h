#pragma once
#include "Board.h"

class Monopoly
{
	int currentPlayerIndex;
	bool hasPair = false;
	bool hasRolled = false;
	static Monopoly* instance;
	Board* board;
	CardDeck* deck;
	MyVector<Player> players;

	void addPlayers();
	void addPlayer(const Player& player);
	void removePlayer(int playerId);
	Monopoly();
public:
	static Monopoly* getInstance();
	static void freeInstance();
	void welcomePlayers();
	int rollDice();
	void stepOnCard();
	void showPlayerData(int id) const;
	void applyFieldEffect(size_t position);

	bool getRolledStatus() const;
	void setPairStatus();
	bool getPairStatus() const;
	const Player& getPlayerOnTurn() const;
	Player& getPlayerOnTurn();
	const Player& getPlayer(int playerId) const;
	Player& getPlayer(int playerId);
	const MyVector<Player>& getPlayers() const;
	MyVector<Player>& getPlayers();
};

