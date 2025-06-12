#include "Property.h"

Property::Property(int boardIndex, const MyString& name, int price, const size_t* rentTiers, size_t housePrice, size_t hotelPrice, ColorSet colorSet)
	: Field(boardIndex), name(name), ownerId(-1), price(price), rentTierIndex(0), housePrice(housePrice), hotelPrice(hotelPrice), colorSet(colorSet)
{
	for (int i = 0; i < GameConstants::RENT_TIERS_COUNT; i++)
	{
		this->rentTiers[i] = rentTiers[i];
	}
}

Property::Property(int ownerId, int boardIndex, const MyString& name, int price, int rentTierIndex, const size_t* rentTiers, size_t housePrice, size_t hotelPrice, ColorSet colorSet)
	: Field(boardIndex), name(name), ownerId(ownerId), price(price), rentTierIndex(rentTierIndex), housePrice(housePrice), hotelPrice(hotelPrice), colorSet(colorSet)
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

Field* Property::clone() const
{
	return new Property(*this);
}

