#pragma once
#include "Field.h"
class CardField : public Field
{
public:
	CardField(int id, const MyString& name, const MyString& abbreviation);
	void applyEffect() override;
	Field* clone() const override;
};

