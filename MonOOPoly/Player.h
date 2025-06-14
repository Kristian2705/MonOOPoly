#pragma once
#include "Property.h"
#include "MyVector.hpp"
#include <memory>
class Card;

class Player
{
	static int nextId;
	int id;
	int money;
	MyString name;
	size_t position;
	int totalBalance;
	bool inGame = true;
	bool inJail = false;
	MyVector<Property*> ownedProperties;
	MyVector<Card*> cards;
public:
	Player() = default;
	Player(const MyString& name, int money = GameConstants::INITIAL_MONEY);
	Player(int id, const MyString& name, int money, size_t position, int totalBalance, bool isInGame, bool inJail, const MyVector<Property*>& properties, const MyVector<Card*>& cards);

	int getId() const;
	int getMoney() const;
	const MyString& getName() const;
	int getTotalBalance() const;
	void setJailStatus();
	size_t getCurrentPosition() const;
	bool isInGame() const;
	bool isInJail() const;
	const MyVector<Property*>& getOwnedProperties();
	const MyVector<Card*>& getCards();

	void addMoney(int amount);
	void resign();
	void moveTo(size_t newPosition);
};

