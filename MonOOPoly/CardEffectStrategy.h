#pragma once
class Player;

class CardEffectStrategy
{
public:
	virtual void execute(Player& player) = 0;
	virtual CardEffectStrategy* clone() const = 0;
	virtual ~CardEffectStrategy() = default;
};

