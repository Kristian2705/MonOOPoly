#include "GoBackThreeSpacesEffect.h"

void GoBackThreeSpacesEffect::execute(Player& player)
{
	int currentPos = player.getCurrentPosition();
	int movePos = currentPos - GameConstants::THREE_STEPS;
	if (GameConstants::THREE_STEPS > currentPos) {
		movePos = GameConstants::BOARD_SIZE - (GameConstants::THREE_STEPS - currentPos);
	}
	player.moveTo(movePos);
}