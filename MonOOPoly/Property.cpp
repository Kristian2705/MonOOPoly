#include "Property.h"

Property::Property(int boardIndex, int price, const size_t* rentTiers) : Field(boardIndex)
{
	this->ownerId = -1;
	this->price = price;
	this->rentTierIndex = 0;
	for (int i = 0; i < Utils::RENT_TIERS_COUNT; i++)
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

