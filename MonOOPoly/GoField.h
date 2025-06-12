#pragma once
#include "Field.h"

class GoField : public Field
{
public:
	GoField() = delete;
	GoField(const MyString& name);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

