#pragma once
#include "Field.h"

class Utility : public Field
{
	Player* owner;
	size_t price = GameConstants::RAILROAD_PRICE;
	int rentMultiplier = GameConstants::UTILITY_FIRST_MULTIPLIER;
public:
	Utility(int boardIndex, const MyString& name, const MyString& abbreviation);
	size_t getPrice() const;
	size_t getRentMultiplier() const;
	Player* getOwner() const;

	void mortgage();
	void showUtility() const;
	void removeOwner();
	void setOwner(Player* player);
	void increaseRentMultiplier();
	void decreaseRentMultiplier();
	int rollRentDice() const;
	void applyEffect(Player& player) override;
	void saveToBinary(std::ofstream& ofs) const override;
	void loadFromBinary(std::ifstream& ifs) override;
};

