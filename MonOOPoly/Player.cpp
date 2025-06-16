#include "Player.h"

int Player::nextId = 1;

Player::Player(const MyString& name, int money)
	: id(nextId++), name(name), money(money), position(GameConstants::GO_FIELD_INDEX), totalBalance(money)
{
	this->ownedProperties = MyVector<Property*>(GameConstants::MIN_CAPACITY);
	this->cards = MyVector<Card*>(GameConstants::MIN_CAPACITY);
}

Player::Player(int id, const MyString& name, int money, size_t position, int totalBalance, bool isInGame, bool inJail, const MyVector<Property*>& properties, const MyVector<Card*>& cards)
{
	this->id = id;
	this->name = name;
	this->money = money;
	this->position = position;
	this->totalBalance = totalBalance;
	this->inGame = isInGame;
	this->inJail = inJail;
	ownedProperties = properties;
	this->cards = cards;
}

int Player::getId() const
{
	return this->id;
}

int Player::getMoney() const
{
	return money;
}

void Player::addProperty(Property* property)
{
	ownedProperties.push_back(property);
	property->setOwner(this);

	std::cout << "You successfully purchased " << property->getName() << " for $" << property->getPrice() << std::endl;

	MyVector<Property*> propsByColor;
	for (int i = 0; i < ownedProperties.getSize(); i++) {
		if (property->getColorSet() == ownedProperties[i]->getColorSet()) {
			propsByColor.push_back(ownedProperties[i]);
		}
	}

	switch (property->getColorSet())
	{
		case ColorSet::Brown:
		case ColorSet::Blue:
			if (propsByColor.getSize() == GameConstants::FIRST_AND_LAST_PROPERTIES_COUNT_BY_COLOR) {
				for (int i = 0; i < propsByColor.getSize(); i++) {
					propsByColor[i]->increaseRentTier();
				}
				std::cout << "You have collected all properties of color " << (int)property->getColorSet() << std::endl;
				std::cout << "You can now build houses and later hotels on the properties of this color to increase the rent!" << std::endl;
			}
			break;
		default:
			if (propsByColor.getSize() == GameConstants::REST_PROPERTIES_COUNT_BY_COLOR_) {
				for (int i = 0; i < propsByColor.getSize(); i++) {
					propsByColor[i]->increaseRentTier();
				}
				std::cout << "You have collected all properties of color " << (int)property->getColorSet() << std::endl;
				std::cout << "You can now build houses and later hotels on the properties of this color to increase the rent!" << std::endl;
			}
			break;
	}
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

void Player::setInDebtStatus()
{
	inDebt = !inDebt;
}

void Player::resign()
{
	inGame = false;
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

bool Player::isInGame() const
{
	return inGame;
}

bool Player::isInJail() const
{
	return inJail;
}

bool Player::isInDebt() const
{
	return inDebt;
}

const MyVector<Property*>& Player::getOwnedProperties() const
{
	return ownedProperties;
}

MyVector<Property*>& Player::getOwnedProperties()
{
	return ownedProperties;
}

const MyVector<Card*>& Player::getCards() const {
	return cards;
}

MyVector<Card*>& Player::getCards()
{
	return cards;
}

void Player::moveTo(size_t newPosition)
{
	position = newPosition;
	std::cout << "You are currently on position " << position << std::endl;
}
