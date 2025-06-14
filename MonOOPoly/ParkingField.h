#pragma once
#include "Field.h"
#include "MyString.h"

class ParkingField : public Field
{
public:
	ParkingField(const MyString& name, const MyString& abbreviation);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

