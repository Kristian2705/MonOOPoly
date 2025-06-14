#include "OperaNightEffect.h"
#include "Monopoly.h"

void OperaNightEffect::execute(Player& player)
{
	MyVector<Player>& players = Monopoly::getInstance()->getPlayers();
	for (int i = 0; i < players.getSize(); i++) {
		if (GameConstants::GRAND_OPERA_NIGHT_REWARD <= players[i].getMoney()) {
			players[i].addMoney(-GameConstants::GRAND_OPERA_NIGHT_REWARD);
			player.addMoney(GameConstants::GRAND_OPERA_NIGHT_REWARD);
		}
		else {
			//To be implemented
		}
	}
}

CardEffectStrategy* OperaNightEffect::clone() const
{
	return new OperaNightEffect(*this);
}
