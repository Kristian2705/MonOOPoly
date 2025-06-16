#pragma once
#include "Field.h"
class Station : public Field
{
	Player* owner;
	size_t price;
	size_t rentTiers[GameConstants::RENT_TIERS_STATION_COUNT];
	int rentTierIndex;
public:
	//Contructors for later
	Station(int boardIndex, const MyString& name, const MyString& abbreviation);
	
	size_t getPrice() const;
	size_t getRent() const;

	//Mortgage function later
	void showStation() const;
	void removeOwner();
	void setOwner(Player* player);
	void increaseRentTier();
	void decreaseRentTier();
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

