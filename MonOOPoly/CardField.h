#pragma once
#include "Field.h"

class Monopoly;
class CardDeck;

class CardField : public Field
{
	CardDeck* deck;
public:
	CardField(int id, const MyString& name, const MyString& abbreviation);
	void applyEffect(Player& player) override;
	void saveToBinary(std::ofstream& ofs) const override;
	void loadFromBinary(std::ifstream& ifs) override;
	Field* clone() const override;
};

