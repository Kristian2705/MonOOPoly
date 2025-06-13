#pragma once
#include "Field.h"

class GoToJailField : public Field
{
public:
	GoToJailField(const MyString& name, const MyString& abbreviation);
	//void putInJail(Player& player) const;
	void applyEffect() override;
	Field* clone() const override;
};

