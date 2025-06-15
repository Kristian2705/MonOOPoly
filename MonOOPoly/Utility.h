#pragma once
#include "Field.h"

class Utility : public Field
{
public:
	Utility(int boardIndex, const MyString& name, const MyString& abbreviation);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

