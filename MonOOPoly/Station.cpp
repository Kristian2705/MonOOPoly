#include "Station.h"
#include "Player.h"
#include "Monopoly.h"

Station::Station(int boardIndex, const MyString& name, const MyString& abbreviation)
	: Field(boardIndex, name, abbreviation), rentTierIndex(GameConstants::START_RENT_TIER)
{
	rentTiers[0] = GameConstants::STATION_FIRST_RENT;
	rentTiers[1] = GameConstants::STATION_SECOND_RENT;
	rentTiers[2] = GameConstants::STATION_THIRD_RENT;
	rentTiers[3] = GameConstants::STATION_FOURTH_RENT;
}

int Station::getRentTierIndex() const
{
	return rentTierIndex;
}

size_t Station::getPrice() const
{
	return price;
}

size_t Station::getRent() const
{
	return rentTiers[rentTierIndex];
}

Player* Station::getOwner() const
{
	return owner;
}

void Station::mortgage() {
	owner->removeStation(this);
	owner = nullptr;
	rentTierIndex = GameConstants::START_RENT_TIER;
}

void Station::showStation() const
{
	std::cout << "--Position: " << boardIndex << std::endl;
	std::cout << "--Name: " << name << std::endl;
	std::cout << "--Price: $" << price << std::endl;
	std::cout << "--Rent: $" << getRent() << std::endl;
}

void Station::removeOwner()
{
	owner = nullptr;
}

void Station::setOwner(Player* player)
{
	owner = player;
}

void Station::setRentTier(int rentTierIndex)
{
	this->rentTierIndex = rentTierIndex;
}

void Station::increaseRentTier()
{
	rentTierIndex++;
}

void Station::decreaseRentTier()
{
	rentTierIndex--;
}

void Station::resetRentTier() {
	rentTierIndex = GameConstants::START_RENT_TIER;
}

void Station::applyEffect(Player& player)
{
	if (owner) {
		if (owner == &player) {
			std::cout << "This station is yours. Home sweet home." << std::endl;
			return;
		}

		if (player.getMoney() >= getRent()) {
			player.addMoney((-1) * getRent());
			owner->addMoney(getRent());
			std::cout << "You successfully paid " << owner->getName() << " a rent of $" << getRent() << std::endl;
		}
		else {
			player.setInDebtStatus();
			std::cout << "You don't have enough money to pay your debt to" << owner->getName() << std::endl;
			std::cout << "You owe $" << getRent() << " but you have $" << player.getMoney() << std::endl;
			std::cout << "Find a way to collect the money or go bankrupt." << std::endl;
			player.setInDebtTo(owner);
			player.setOwedMoney(getRent());
		}
		return;
	}

	if (price > player.getMoney()) {
		std::cout << "You landed on " << name << " which costs $" << price << std::endl;
		std::cout << "But you don't have enough money to get it. So it is still unowned." << std::endl;
		//Auction might be needed here
		return;
	}

	std::cout << "You landed on " << name << " which costs $" << price << std::endl;
	std::cout << "Do you want to purchase it for $" << price << std::endl;
	std::cout << "You currently have: $" << player.getMoney() << std::endl;
	std::cout << "Type 'yes' or 'no'." << std::endl;

	MyString answer;
	std::cin >> answer;

	while (true) {
		if (answer == "no") {
			std::cout << "You are chilling. You may buy it later if it is still unowned." << std::endl;
			return;
		}
		if (answer == "yes") {
			player.addMoney((-1) * price);
			player.addStation(this);
			return;
		}
		std::cout << "Invalid input. Please type 'yes' or 'no'." << std::endl;
		std::cin >> answer;
	}
}

void Station::saveToBinary(std::ofstream& ofs) const
{
	ofs.write((const char*)(&rentTierIndex), sizeof(rentTierIndex));
	if (owner) 
	{
		int ownerId = owner->getId();
		ofs.write((const char*)(&ownerId), sizeof(ownerId));
	} 
	else 
	{
		int ownerId = GameConstants::INVALID_PLAYER_ID;
		ofs.write((const char*)(&ownerId), sizeof(ownerId));
	}
}

void Station::loadFromBinary(std::ifstream& ifs)
{
	ifs.read((char*)(&rentTierIndex), sizeof(rentTierIndex));
	int ownerId;
	ifs.read((char*)(&ownerId), sizeof(ownerId));
	if (ownerId != GameConstants::INVALID_PLAYER_ID) 
	{
		Player& player = Monopoly::getInstance()->getPlayer(ownerId);
		owner = &player;
		player.addStation(this);
	} 
	else 
	{
		owner = nullptr;
	}
}

Field* Station::clone() const
{
	return new Station(*this);
}
