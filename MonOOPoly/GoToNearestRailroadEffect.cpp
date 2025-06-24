#include "GoToNearestRailroadEffect.h"

void GoToNearestRailroadEffect::execute(Player& player)
{
	int currPos = player.getCurrentPosition();
	int stationsPos[] = { GameConstants::READING_RAILROAD_LOCATION, 
		GameConstants::PENNSYLVANIA_RAILROAD_LOCATION, 
		GameConstants::BO_RAILROAD_LOCATION , 
		GameConstants::SHORT_LINE_RAILROAD_LOCATION };
	int moveToPos = GameConstants::READING_RAILROAD_LOCATION;

	for (int i = 0; i < GameConstants::TOTAL_STATIONS; i++) {
		if (currPos > stationsPos[i]) {
			continue;
		}
		moveToPos = stationsPos[i];
		break;
	}

	player.moveTo(moveToPos);
}
