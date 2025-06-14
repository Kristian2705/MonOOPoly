#include "BirthdayEffect.h"
#include "Monopoly.h"

void BirthdayEffect::execute(Player& player)
{
	MyVector<Player>& players = Monopoly::getInstance()->getPlayers();
	for (int i = 0; i < players.getSize(); i++) {
		if (GameConstants::BIRTHDAY_REWARD <= players[i].getMoney()) {
			players[i].addMoney(-GameConstants::BIRTHDAY_REWARD);
			player.addMoney(GameConstants::BIRTHDAY_REWARD);
		}
		else {
			//To be implemented
		}
	}
}

CardEffectStrategy* BirthdayEffect::clone() const
{
	return new BirthdayEffect(*this);
}
