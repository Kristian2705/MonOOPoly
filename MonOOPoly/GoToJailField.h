#pragma once
#include "Field.h"
#include "Player.h"

class GoToJailField : public Field
{
public:
	GoToJailField();
	void putInJail(Player& player) const;
	virtual Field* clone() const override;
};

