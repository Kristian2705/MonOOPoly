#pragma once
#include "Field.h"
class Station : public Field
{
	int ownerId;
	size_t price;
	size_t rent;
public:
	Station() = delete;
	Station(int boardIndex, const MyString& name);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

