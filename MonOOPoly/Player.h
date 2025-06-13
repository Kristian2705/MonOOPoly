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
	bool isInGame = true;
	bool inJail = false;
	MyVector<Property> ownedProperties;
	MyVector<std::shared_ptr<Card>> cards;
public:
	Player() = default;
	Player(const MyString& name, int money = GameConstants::INITIAL_MONEY);
	Player(int id, const MyString& name, int money, size_t position, int totalBalance, bool inJail);
	int getId() const;
	int getMoney() const;
	void addMoney(int amount);
	const MyString& getName() const;
	int getTotalBalance() const;
	void setJailStatus();
	void resign();
	size_t getCurrentPosition() const;
	bool isInJail() const;
	void moveTo(size_t newPosition);
};

