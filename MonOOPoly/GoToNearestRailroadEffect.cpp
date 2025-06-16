#include "GoToNearestRailroadEffect.h"

void GoToNearestRailroadEffect::execute(Player& player)
{
	int currPos = player.getCurrentPosition();
	int stationsPos[] = { GameConstants::READING_RAILROAD_LOCATION, 
		GameConstants::PENNSYLVANIA_RAILROAD_LOCATION, 
		GameConstants::BO_RAILROAD_LOCATION , 
		GameConstants::SHORT_LINE_RAILROAD_LOCATION };
	int moveToPos = GameConstants::READING_RAILROAD_LOCATION;
	bool wasIn = false;
	for (int i = 0; i < GameConstants::TOTAL_STATIONS; i++) {
		if (currPos > stationsPos[i]) {
			continue;
		}
		wasIn = true;
		moveToPos = stationsPos[i];
		break;
	}
	if (!wasIn) {
		std::cout << "You passed GO! Collect $200!";
		player.addMoney(GameConstants::PASS_GO_BONUS);
	}
	player.moveTo(moveToPos);
}

CardEffectStrategy* GoToNearestRailroadEffect::clone() const
{
	return new GoToNearestRailroadEffect(*this);
}
