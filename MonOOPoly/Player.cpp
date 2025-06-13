#include "Player.h"

int Player::nextId = 1;

Player::Player(const MyString& name, int money)
	: id(nextId++), name(name), money(money), position(GameConstants::GO_FIELD_INDEX), totalBalance(money)
{
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

int Player::getId() const
{
	return this->id;
}

int Player::getMoney() const
{
	return money;
}

void Player::addMoney(int amount)
{
	money += amount;
	totalBalance += amount;
}

const MyString& Player::getName() const
{
	return name;
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

void Player::resign()
{
	isInGame = false;
	totalBalance = 0;
	money = 0;
	position = GameConstants::INVALID_POSITION;
	inJail = false;
	ownedProperties.clear();
}

size_t Player::getCurrentPosition() const
{
	return position;
}

bool Player::isInJail() const
{
	return inJail;
}

void Player::moveTo(size_t newPosition)
{
	position = newPosition;
}
