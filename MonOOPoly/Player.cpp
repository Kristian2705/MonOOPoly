#include "Player.h"

Player::Player(const MyString& name, int money)
{
	this->name = name;
	this->money = money;
	this->position = 0;
	this->totalBalance = money;
	this->inJail = false;
	this->ownedProperties = MyVector<Property>(Utils::MIN_CAPACITY);
}

Player::Player(const MyString& name, int money, size_t position, int totalBalance, bool inJail)
{
	this->name = name;
	this->money = money;
	this->position = position;
	this->totalBalance = totalBalance;
	this->inJail = inJail;
}

int Player::getMoney() const
{
	return money;
}

int Player::getTotalBalance() const
{
	return totalBalance;
}

size_t Player::getCurrentPosition() const
{
	return position;
}

bool Player::isInJail() const
{
	return inJail;
}
