#pragma once
#include "Field.h"

class GoToJailField : public Field
{
public:
	GoToJailField(const MyString& name, const MyString& abbreviation);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

