#include "Property.h"
#include "Player.h"

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
	return rentTierIndex - 1;
}

void Property::applyEffect(Player& player)
{
	if (!owner) {
		std::cout << "Do you want to purchase " << name << " for " << price;
	}
	//Maybe it will be better to implement the commands first
}

Field* Property::clone() const
{
	return new Property(*this);
}

