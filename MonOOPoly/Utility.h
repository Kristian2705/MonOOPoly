#pragma once
#include "Field.h"

class Utility : public Field
{
	Player* owner;
	size_t price = GameConstants::RAILROAD_PRICE;
	int rentMultiplier = GameConstants::UTILITY_FIRST_MULTIPLIER;
public:
	//Constructors for later
	Utility(int boardIndex, const MyString& name, const MyString& abbreviation);
	size_t getPrice() const;
	size_t getRentMultiplier() const;

	//Mortgage function later
	void showUtility() const;
	void removeOwner();
	void setOwner(Player* player);
	void increaseRentMultiplier();
	void decreaseRentMultiplier();
	int rollRentDice() const;
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

