#include "Field.h"

Field::Field(int boardIndex, const MyString& name, const MyString& abbreviation)
	: boardIndex(boardIndex), name(name), abbreviation(abbreviation)
{ }

const MyString& Field::getName() const
{
	return name;
}

const MyString& Field::getAbbreviation() const
{
	return abbreviation;
}