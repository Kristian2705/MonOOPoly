#pragma once


class Field
{
	int boardIndex;
public:
	Field() = default;
	Field(int boardIndex);
	//virtual void applyEffect() = 0;
	virtual Field* clone() const = 0;
	virtual ~Field() = default;
};

