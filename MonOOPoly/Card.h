#pragma once
#include "MyString.h"

class Card
{
	MyString description;
public:
	Card(const MyString& description);
	virtual void applyEffect() const = 0;
	virtual Card* clone() const = 0;
	virtual ~Card() = default;
};

