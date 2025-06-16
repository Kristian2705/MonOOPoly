#pragma once
#include "Field.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Enums.h"

class Property : public Field
{
	Player* owner;
	size_t price;
	size_t rentTiers[GameConstants::RENT_TIERS_COUNT];
	int rentTierIndex;
	size_t housePrice;
	size_t hotelPrice;
	ColorSet colorSet;
public:
	Property() = default;
	Property(int boardIndex, const MyString& name, const MyString& abbreviation, int price, const size_t* rentTiers, size_t housePrice, size_t hotelPrice ,ColorSet colorSet);
	Property(Player* owner, int boardIndex, const MyString& name, const MyString& abbreviation, int price, int rentTierIndex, const size_t* rentTiers, size_t housePrice, size_t hotelPrice, ColorSet colorSet);

	Player* getOwner();
	int getPrice() const;
	size_t getRent() const;
	int getBuildsCount() const;
	ColorSet getColorSet() const;

	void showProperty() const;
	void removeOwner();
	void setOwner(Player* player);
	void increaseRentTier();
	void decreaseRentTier();
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

