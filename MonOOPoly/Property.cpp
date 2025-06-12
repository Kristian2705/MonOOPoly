#include "Property.h"

Property::Property(int boardIndex, const MyString& name, int price, const size_t* rentTiers, size_t housePrice, size_t hotelPrice, ColorSet colorSet)
	: Field(boardIndex, name), ownerId(GameConstants::INVALID_PLAYER_ID), price(price), rentTierIndex(GameConstants::START_RENT_TIER), housePrice(housePrice), hotelPrice(hotelPrice), colorSet(colorSet)
{
	for (int i = 0; i < GameConstants::RENT_TIERS_COUNT; i++)
	{
		this->rentTiers[i] = rentTiers[i];
	}
}

Property::Property(int ownerId, int boardIndex, const MyString& name, int price, int rentTierIndex, const size_t* rentTiers, size_t housePrice, size_t hotelPrice, ColorSet colorSet)
	: Field(boardIndex, name), ownerId(ownerId), price(price), rentTierIndex(rentTierIndex), housePrice(housePrice), hotelPrice(hotelPrice), colorSet(colorSet)
{
	for (int i = 0; i < GameConstants::RENT_TIERS_COUNT; i++)
	{
		this->rentTiers[i] = rentTiers[i];
	}
}

int Property::getOwnerId() const
{
	return ownerId;
}

int Property::getPrice() const
{
	return price;
}

size_t Property::getRent() const
{
	return rentTiers[rentTierIndex];
}

void Property::applyEffect(Player& player)
{
	// This method should implement the effect of landing on this property.
	// For example, if the property is owned by another player, charge rent.
	// If the property is unowned, allow the current player to buy it.
	// If the property is owned by the current player, do nothing.
	// This is a placeholder implementation.
	std::cout << "Applying effect of property" << std::endl;
}

Field* Property::clone() const
{
	return new Property(*this);
}

