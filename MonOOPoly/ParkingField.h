#pragma once
#include "Field.h"
#include "MyString.h"

class ParkingField : public Field
{
public:
	ParkingField(const MyString& name, const MyString& abbreviation);
	void applyEffect(Player& player) override;
	void saveToBinary(std::ofstream& ofs) const override;
	void loadFromBinary(std::ifstream& ifs) override;
	Field* clone() const override;
};

