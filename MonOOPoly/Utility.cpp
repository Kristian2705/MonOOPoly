#include "Utility.h"
#include "Player.h"
#include "Monopoly.h"

Utility::Utility(int boardIndex, const MyString& name, const MyString& abbreviation)
	: Field(boardIndex, name, abbreviation)
{ }

size_t Utility::getPrice() const
{
	return price;
}

size_t Utility::getRentMultiplier() const
{
	return rentMultiplier;
}

Player* Utility::getOwner() const {
	return owner;
}

void Utility::mortgage() {
	owner->removeUtility(this);
	owner = nullptr;
	rentMultiplier = GameConstants::UTILITY_FIRST_MULTIPLIER;
}

void Utility::showUtility() const
{
	std::cout << "--Position: " << boardIndex << std::endl;
	std::cout << "--Name: " << name << std::endl;
	std::cout << "--Price: $" << price << std::endl;
	std::cout << "--Rent Multiplier: " << rentMultiplier << "x" << std::endl;
}

void Utility::removeOwner()
{
	owner = nullptr;
}

void Utility::setOwner(Player* player)
{
	owner = player;
}

void Utility::increaseRentMultiplier()
{
	rentMultiplier = GameConstants::UTILITY_SECOND_MULTIPLIER;
}

void Utility::decreaseRentMultiplier()
{
	rentMultiplier = GameConstants::UTILITY_FIRST_MULTIPLIER;
}

int Utility::rollRentDice() const
{
	std::cout << "Press Enter to roll..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int total = die1 + die2;
	std::cout << "You rolled: " << die1 << " and " << die2 << " (Total: " << total << ")" << std::endl;
	return total;
}

void Utility::applyEffect(Player& player)
{
	if (owner) {
		if (owner == &player) {
			std::cout << "This utility is yours. Home sweet home." << std::endl;
			return;
		}

		int calculatedRent = rollRentDice() * rentMultiplier;

		if (player.getMoney() >= calculatedRent) {
			player.addMoney((-1) * calculatedRent);
			owner->addMoney(calculatedRent);
			std::cout << "You successfully paid " << owner->getName() << " a rent of $" << calculatedRent << std::endl;
		}
		else {
			player.setInDebtStatus();
			std::cout << "You don't have enough money to pay your debt to" << owner->getName() << std::endl;
			std::cout << "You owe $" << calculatedRent << " but you have $" << player.getMoney() << std::endl;
			std::cout << "Find a way to collect the money or go bankrupt." << std::endl;
			player.setInDebtTo(owner);
			player.setOwedMoney(calculatedRent);
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
			player.addUtility(this);
			return;
		}
		std::cout << "Invalid input. Please type 'yes' or 'no'." << std::endl;
		std::cin >> answer;
	}
}

void Utility::saveToBinary(std::ofstream& ofs) const
{
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

void Utility::loadFromBinary(std::ifstream& ifs)
{
	int ownerId;
	ifs.read((char*)(&ownerId), sizeof(ownerId));
	if (ownerId != GameConstants::INVALID_PLAYER_ID)
	{
		Player& player = Monopoly::getInstance()->getPlayer(ownerId);
		owner = &player;
		player.addUtility(this);
	} 
	else 
	{
		owner = nullptr;
	}
}
