#pragma once
#include "Constants.h"

class Field
{
	int boardIndex;
public:
	Field(int boardIndex);
	//virtual void applyEffect() = 0;
	virtual Field* clone() const = 0;
	virtual ~Field() = default;
};

