#pragma once
#include "Field.h"

class Property : public Field
{
	int ownerId;
	size_t price;
	size_t rentTiers[Utils::RENT_TIERS_COUNT];
	int rentTierIndex;
	size_t housePrice;
	size_t hotelPrice;
public:
	Property(int boardIndex, int price, const size_t* rentTiers);
	int getOwnerId() const;
	int getPrice() const;
	size_t getRent() const;
	Field* clone() const override;
};

