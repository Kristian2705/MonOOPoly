#include "Player.h"
#include "Card.h"
#include "Monopoly.h"

int Player::nextId = 1;

Player::Player(const MyString& name, int money)
	: id(nextId++), name(name), money(money), position(GameConstants::GO_FIELD_INDEX), totalBalance(money)
{
	this->ownedProperties = MyVector<Property*>(GameConstants::MIN_CAPACITY);
	this->ownedStations = MyVector<Station*>(GameConstants::MIN_CAPACITY);
	this->ownedUtilities = MyVector<Utility*>(GameConstants::MIN_CAPACITY);
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

void Player::addStation(Station* station)
{
	ownedStations.push_back(station);
	station->setOwner(this);
	std::cout << "You successfully purchased " << station->getName() << " for $" << station->getPrice() << std::endl;

	int ownedStationsCount = ownedStations.getSize();
	if (ownedStationsCount > 1) {
		for (int i = 0; i < ownedStationsCount; i++) {
			ownedStations[i]->increaseRentTier();
		}
	}
	std::cout << "You currently have " << ownedStationsCount << " stations. Their rent is $" << station->getRent() << std::endl;
}

void Player::addReleaseCard()
{
	releaseCards++;
}

void Player::removeReleaseCard()
{
	releaseCards--;
}

void Player::addUtility(Utility* utility)
{
	ownedUtilities.push_back(utility);
	utility->setOwner(this);
	std::cout << "You successfully purchased " << utility->getName() << " for $" << utility->getPrice() << std::endl;
	int ownedUtilitiesCount = ownedUtilities.getSize();
	if (ownedUtilitiesCount > 1) {
		for (int i = 0; i < ownedUtilitiesCount; i++) {
			ownedUtilities[i]->increaseRentMultiplier();
		}
	}
	std::cout << "You currently have " << ownedUtilitiesCount << " stations. Their rent multiplier is " << utility->getRentMultiplier() << "x" << std::endl;
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

void Player::removeProperty(Property* property)
{
	int index = -1;
	for (int i = 0; i < ownedProperties.getSize(); i++) {
		if (property == ownedProperties[i]) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		throw std::invalid_argument("Invalid index for removal of properties!");
	}

	ownedProperties.erase(index);
}

void Player::removeStation(Station* station)
{
	int index = -1;
	for (int i = 0; i < ownedStations.getSize(); i++) {
		if (station == ownedStations[i]) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		throw std::invalid_argument("Invalid index for removal of stations!");
	}

	ownedStations.erase(index);
}

void Player::removeUtility(Utility* utility)
{
	int index = -1;
	for (int i = 0; i < ownedUtilities.getSize(); i++) {
		if (utility == ownedUtilities[i]) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		throw std::invalid_argument("Invalid index for removal of utilities!");
	}

	ownedUtilities.erase(index);
}

void Player::decreaseTimesLeft()
{
	timesLeftToRollInJail--;
}

void Player::setJailStatus()
{
	inJail = !inJail;
	if (inJail)
	{
		position = GameConstants::JAIL_POSITION;
	}
	else {
		timesLeftToRollInJail = GameConstants::TIMES_TO_ROLL_IN_JAIL;
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

const MyVector<Station*>& Player::getOwnedStations() const
{
	return ownedStations;
}

MyVector<Station*>& Player::getOwnedStations()
{
	return ownedStations;
}

int Player::getCards() const
{
	return releaseCards;
}

const MyVector<Utility*>& Player::getUtilities() const
{
	return ownedUtilities;
}

MyVector<Utility*>& Player::getUtilities()
{
	return ownedUtilities;
}

int Player::getTimesLeft() const
{
	return timesLeftToRollInJail;
}

void Player::moveTo(size_t newPosition)
{
	int currentPosition = position;
	position = newPosition % GameConstants::BOARD_SIZE;
	if (position < currentPosition) {
		std::cout << "You passed GO! Collect $200!" << std::endl;
		addMoney(GameConstants::PASS_GO_BONUS);
	}
	std::cout << "You are currently on position " << position << std::endl;
	if (inJail) {
		return;
	}
	Monopoly* game = Monopoly::getInstance();
	game->applyFieldEffect(position);
}

void Player::showInfo() const
{
	std::cout << "Player name: " << name << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Money: $" << money << std::endl;
	std::cout << "Position: " << position << std::endl;
	std::cout << "In jail: " << (inJail ? "Yes" : "No") << std::endl;
	std::cout << "In debt: " << (inDebt ? "Yes" : "No") << std::endl;
	std::cout << "Owned properties count: " << ownedProperties.getSize() << std::endl;
	if (ownedProperties.getSize()) {
		for (int i = 0; i < ownedProperties.getSize(); i++) {
			ownedProperties[i]->showProperty();
			std::cout << std::endl;
		}
	}
	std::cout << "Owned stations count: " << ownedStations.getSize() << std::endl;
	if (ownedStations.getSize()) {
		for (int i = 0; i < ownedStations.getSize(); i++) {
			ownedStations[i]->showStation();
			std::cout << std::endl;
		}
	}
	std::cout << "Release cards in hold: " << releaseCards << std::endl;

	std::cout << "Owned Utilities: " << ownedUtilities.getSize() << std::endl;
	if (ownedUtilities.getSize()) {
		for (int i = 0; i < ownedUtilities.getSize(); i++) {
			ownedUtilities[i]->showUtility();
			std::cout << std::endl;
		}
	}
}