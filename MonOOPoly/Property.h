#pragma once
#include "Field.h"
#include "MyString.h"
#include "Enums.h"

class Property : public Field
{
	int ownerId;
	MyString name;
	size_t price;
	size_t rentTiers[GameConstants::RENT_TIERS_COUNT];
	int rentTierIndex;
	size_t housePrice;
	size_t hotelPrice;
	ColorSet colorSet;
public:
	Property() = default;
	Property(int boardIndex, const MyString& name, int price, const size_t* rentTiers, size_t housePrice, size_t hotelPrice ,ColorSet colorSet);
	Property(int ownerId, int boardIndex, const MyString& name, int price, int rentTierIndex, const size_t* rentTiers, size_t housePrice, size_t hotelPrice, ColorSet colorSet);
	int getOwnerId() const;
	int getPrice() const;
	size_t getRent() const;
	Field* clone() const override;
};

