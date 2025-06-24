#include "Property.h"
#include "Player.h"
#include "Monopoly.h"

Property::Property(int boardIndex, const MyString& name, const MyString& abbreviation, int price, const size_t* rentTiers, size_t housePrice, size_t hotelPrice, ColorSet colorSet)
	: Field(boardIndex, name, abbreviation), owner(nullptr), price(price), rentTierIndex(GameConstants::START_RENT_TIER), housePrice(housePrice), hotelPrice(hotelPrice), colorSet(colorSet)
{
	for (int i = 0; i < GameConstants::RENT_TIERS_COUNT; i++)
	{
		this->rentTiers[i] = rentTiers[i];
	}
}

Property::Property(Player* owner, int boardIndex, const MyString& name, const MyString& abbreviation, int price, int rentTierIndex, const size_t* rentTiers, size_t housePrice, size_t hotelPrice, ColorSet colorSet)
	: Field(boardIndex, name, abbreviation), owner(owner), price(price), rentTierIndex(rentTierIndex), housePrice(housePrice), hotelPrice(hotelPrice), colorSet(colorSet)
{
	for (int i = 0; i < GameConstants::RENT_TIERS_COUNT; i++)
	{
		this->rentTiers[i] = rentTiers[i];
	}
}

Player* Property::getOwner()
{
	return owner;
}

int Property::getPrice() const
{
	return price;
}

size_t Property::getRent() const
{
	return rentTiers[rentTierIndex];
}

int Property::getBuildsCount() const
{
	if (rentTierIndex - 1 <= 0) {
		return 0;
	}
	return rentTierIndex - 1;
}

int Property::getRentTierIndex() const
{
	return rentTierIndex;
}

ColorSet Property::getColorSet() const
{
	return colorSet;
}

size_t Property::getHousePrice() const
{
	return housePrice;
}

size_t Property::getHotelPrice() const
{
	return hotelPrice;
}

void Property::mortgage()
{
	owner->removeProperty(this);
	owner = nullptr;
	rentTierIndex = GameConstants::START_RENT_TIER;
}

void Property::showProperty() const
{
	std::cout << "--Position: " << boardIndex << std::endl;
	std::cout << "--Name: " << name << std::endl;
	std::cout << "--Color: " << (int)colorSet << std::endl;
	std::cout << "--Price: $" << price << std::endl;
	std::cout << "--Rent: $" << getRent() << std::endl;
	std::cout << "--Buildings count: " << ((rentTierIndex - 1) < 0 ? 0 : rentTierIndex - 1) << std::endl;
	std::cout << "--House price: $" << housePrice << std::endl;
	std::cout << "--Hotel price: $" << hotelPrice << std::endl;
}

void Property::removeOwner()
{
	owner = nullptr;
}

void Property::setOwner(Player* player)
{
	owner = player;
}

void Property::increaseRentTier()
{
	rentTierIndex++;
}

void Property::decreaseRentTier()
{
	rentTierIndex--;
}

void Property::resetRentTier()
{
	rentTierIndex = GameConstants::START_RENT_TIER;
}

void Property::applyEffect(Player& player)
{
	if (owner) {
		if (owner == &player) {
			std::cout << "This property is yours. Home sweet home." << std::endl;
			return;
		}

		if (player.getMoney() >= getRent()) {
			player.addMoney((-1)*getRent());
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
			player.addMoney((- 1)*price);
			player.addProperty(this);
			return;
		}
		std::cout << "Invalid input. Please type 'yes' or 'no'." << std::endl;
		std::cin >> answer;
	}

}

void Property::saveToBinary(std::ofstream& ofs) const
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

void Property::loadFromBinary(std::ifstream& ifs)
{
	ifs.read((char*)(&rentTierIndex), sizeof(rentTierIndex));
	int ownerId;
	ifs.read((char*)(&ownerId), sizeof(ownerId));
	if (ownerId != GameConstants::INVALID_PLAYER_ID)
	{
		Player& player = Monopoly::getInstance()->getPlayer(ownerId);
		owner = &player;
		player.addProperty(this);
	} 
	else 
	{
		owner = nullptr;
	}
}

Field* Property::clone() const
{
	return new Property(*this);
}

