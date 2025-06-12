#pragma once
#include "Field.h"

class GoToJailField : public Field
{
public:
	GoToJailField() = delete;
	GoToJailField(const MyString& name);
	void putInJail(Player& player) const;
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

