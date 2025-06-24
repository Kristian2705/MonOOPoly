#pragma once
#include "Field.h"

class GoToJailField : public Field
{
public:
	GoToJailField(const MyString& name, const MyString& abbreviation);
	void applyEffect(Player& player) override;
	void saveToBinary(std::ofstream& ofs) const override;
	void loadFromBinary(std::ifstream& ifs) override;
	Field* clone() const override;
};

