#pragma once
#include "MyString.h"
#include <iostream>

class Player;

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
	int getBoardIndex() const;

	virtual void applyEffect(Player& player) = 0;
	virtual Field* clone() const = 0;
	virtual void saveToBinary(std::ofstream& ofs) const = 0;
	virtual void loadFromBinary(std::ifstream& ifs) = 0;
	virtual ~Field() = default;
};

