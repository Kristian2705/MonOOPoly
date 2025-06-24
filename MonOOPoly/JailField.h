#pragma once
#include "Field.h"
class JailField : public Field
{
public:
	JailField(const MyString& name, const MyString& abbreviation);
	void applyEffect(Player& player) override;
	void saveToBinary(std::ofstream& ofs) const override;
	void loadFromBinary(std::ifstream& ifs) override;
};

