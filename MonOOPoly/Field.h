#pragma once
#include "MyString.h"
#include "Player.h"

class Field
{
protected:
	int boardIndex;
	MyString name;
public:
	Field() = default;
	Field(int boardIndex, const MyString& name);
	virtual void applyEffect(Player& player) = 0;
	virtual Field* clone() const = 0;
	virtual ~Field() = default;
};

