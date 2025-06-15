#include "Station.h"

Station::Station(int boardIndex, const MyString& name, const MyString& abbreviation)
	: Field(boardIndex, name, abbreviation)
{ }

void Station::applyEffect(Player& player)
{
	std::cout << "You landed on " << name << ". This is a station." << std::endl;
	// Implement the effect of landing on a station.
	// For example, if the station is owned by another player, charge rent.
	// If the station is unowned, allow the current player to buy it.
	// If the station is owned by the current player, do nothing.
}
Field* Station::clone() const
{
	return new Station(*this);
}
