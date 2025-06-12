#include "Player.h"

int Player::nextId = 1;

Player::Player(const MyString& name, int money)
{
	this->id = nextId++;
	this->name = name;
	this->money = money;
	this->position = 0;
	this->totalBalance = money;
	this->inJail = false;
	this->ownedProperties = MyVector<Property>(GameConstants::MIN_CAPACITY);
}

Player::Player(int id, const MyString& name, int money, size_t position, int totalBalance, bool inJail)
{
	this->id = id;
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

void Player::setJailStatus()
{
	inJail = !inJail;
	if (inJail)
	{
		position = GameConstants::JAIL_POSITION;
	}
}

size_t Player::getCurrentPosition() const
{
	return position;
}

bool Player::isInJail() const
{
	return inJail;
}
