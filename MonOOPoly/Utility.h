#pragma once
#include "Field.h"

class Utility : public Field
{
public:
	Utility() = default;
	Utility(int boardIndex, const MyString& name);
	void applyEffect(Player& player) override;
	Field* clone() const override;;
};

