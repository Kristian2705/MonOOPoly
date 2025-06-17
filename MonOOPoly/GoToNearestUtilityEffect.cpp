#include "GoToNearestUtilityEffect.h"

void GoToNearestUtilityEffect::execute(Player& player)
{
	int currPos = player.getCurrentPosition();
	int utilsPos[GameConstants::TOTAL_UTILITIES] = { GameConstants::ELECTRIC_COMPANY_LOCATION, 
		GameConstants::WATER_WORKS_LOCATION };
	int moveToPos = GameConstants::ELECTRIC_COMPANY_LOCATION;
	//bool wasIn = false;
	for (int i = 0; i < GameConstants::TOTAL_UTILITIES; i++) {
		if (currPos > utilsPos[i]) {
			continue;
		}
		//wasIn = true;
		moveToPos = utilsPos[i];
		break;
	}
	//if (!wasIn) {
	//	std::cout << "You passed GO! Collect $200!" << std::endl;
	//	player.addMoney(GameConstants::PASS_GO_BONUS);
	//}
	player.moveTo(moveToPos);
}

CardEffectStrategy* GoToNearestUtilityEffect::clone() const
{
	return new GoToNearestUtilityEffect(*this);
}
