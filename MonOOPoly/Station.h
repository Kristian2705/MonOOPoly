#pragma once
#include "Field.h"
class Station : public Field
{
	int ownerId;
	size_t price;
	size_t rent;
public:
	Station(int boardIndex, const MyString& name, const MyString& abbreviation);
	void applyEffect() override;
	Field* clone() const override;
};

