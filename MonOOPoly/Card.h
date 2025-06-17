#pragma once
#include "MyString.h"
#include "CardEffectStrategy.h"
#include <iostream>

class Card
{
	MyString description;
	std::unique_ptr<CardEffectStrategy> effectStrategy;
public:
	Card(const MyString& description, std::unique_ptr<CardEffectStrategy> effectStrategy);
	const MyString& getDescription() const;
	void applyEffect(Player& player);
};

