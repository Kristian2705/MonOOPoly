#pragma once
#include "Field.h"
class Station : public Field
{
	Player* owner;
	size_t price = GameConstants::RAILROAD_PRICE;
	size_t rentTiers[GameConstants::RENT_TIERS_STATION_COUNT];
	int rentTierIndex;
public:
	//Contructors for later
	Station(int boardIndex, const MyString& name, const MyString& abbreviation);
	
	int getRentTierIndex() const;
	size_t getPrice() const;
	size_t getRent() const;
	Player* getOwner() const;

	void mortgage();
	void showStation() const;
	void removeOwner();
	void setOwner(Player* player);
	void setRentTier(int rentTierIndex);
	void increaseRentTier();
	void decreaseRentTier();
	void resetRentTier();
	void applyEffect(Player& player) override;
	void saveToBinary(std::ofstream& ofs) const override;
	void loadFromBinary(std::ifstream& ifs) override;
	Field* clone() const override;
};
