#pragma once
#include "MyString.h"
#include <iostream>

class Player;
//Apply effect with Player&

class Field
{
protected:
	int boardIndex;
	MyString name;
	MyString abbreviation;
public:
	Field() = default;
	Field(int boardIndex, const MyString& name, const MyString& abbreviation);
	const MyString& getName() const;
	const MyString& getAbbreviation() const;
	virtual void applyEffect() = 0;
	virtual Field* clone() const = 0;
	virtual ~Field() = default;
};

