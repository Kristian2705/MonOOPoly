#pragma once
#include "MyString.h"
#include "Property.h"
#include "MyVector.hpp"

class Player
{
	int money;
	MyString name;
	size_t position;
	int totalBalance;
	bool inJail;
	MyVector<Property> ownedProperties;
public:
	Player(const MyString& name, int money = Utils::INITIAL_MONEY);
	Player(const MyString& name, int money, size_t position, int totalBalance, bool inJail);
	int getMoney() const;
	int getTotalBalance() const;
	size_t getCurrentPosition() const;
	bool isInJail() const;
};

