#pragma once
#include "Field.h"

class Monopoly;

class TaxField : public Field
{
	int taxAmount;
public:
	TaxField(int boardIndex, const MyString& name, const MyString& abbreviation, int taxAmount);
	void applyEffect(Player& player) override;
	void saveToBinary(std::ofstream& ofs) const override;
	void loadFromBinary(std::ifstream& ifs) override; 
	Field* clone() const override;
};

