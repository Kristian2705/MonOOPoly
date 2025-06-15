#pragma once
#include "Field.h"
class JailField : public Field
{
public:
	JailField(const MyString& name, const MyString& abbreviation);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

