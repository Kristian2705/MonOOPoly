#pragma once
#include "Board.h"

class Monopoly
{
	int currentPlayerIndex;
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
	void startGame();
	void welcomePlayers() const;
	int rollDice() const;
	const Player& getPlayer(int playerId) const;
	Player& getPlayer(int playerId);
	const MyVector<Player>& getPlayers() const;
	MyVector<Player>& getPlayers();
	void showPlayerData(int id) const;
	void nextTurn();
};

