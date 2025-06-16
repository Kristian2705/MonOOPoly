#include "GoBackThreeSpacesEffect.h"

void GoBackThreeSpacesEffect::execute(Player& player)
{
	int currentPos = player.getCurrentPosition();
	int movePos = currentPos - 3;
	if (3 > currentPos) {
		movePos = GameConstants::BOARD_SIZE - (3 - currentPos);
	}
	player.moveTo(movePos);
}

CardEffectStrategy* GoBackThreeSpacesEffect::clone() const
{
	return new GoBackThreeSpacesEffect(*this);
}
