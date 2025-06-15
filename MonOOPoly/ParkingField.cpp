#include "ParkingField.h"

ParkingField::ParkingField(const MyString& name, const MyString& abbreviation)
	: Field(GameConstants::PARKING_FIELD_INDEX, name, abbreviation)
{ }

void ParkingField::applyEffect(Player& player)
{
	std::cout << "Free parking! You can rest here." << std::endl;
}

Field* ParkingField::clone() const
{
	return new ParkingField(*this);
}
