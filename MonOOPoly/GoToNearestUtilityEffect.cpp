#include "GoToNearestUtilityEffect.h"

void GoToNearestUtilityEffect::execute(Player& player)
{
	int currPos = player.getCurrentPosition();
	int utilsPos[GameConstants::TOTAL_UTILITIES] = { GameConstants::ELECTRIC_COMPANY_LOCATION, 
		GameConstants::WATER_WORKS_LOCATION };
	int moveToPos = GameConstants::ELECTRIC_COMPANY_LOCATION;

	for (int i = 0; i < GameConstants::TOTAL_UTILITIES; i++) {
		if (currPos > utilsPos[i]) {
			continue;
		}
		moveToPos = utilsPos[i];
		break;
	}

	player.moveTo(moveToPos);
}

CardEffectStrategy* GoToNearestUtilityEffect::clone() const
{
	return new GoToNearestUtilityEffect(*this);
}
