#pragma once
#include "Field.h"
class JailField : public Field
{
public:
	JailField() = delete;
	JailField(const MyString& name);
	void applyEffect(Player& player) override;
	Field* clone() const override;
};

