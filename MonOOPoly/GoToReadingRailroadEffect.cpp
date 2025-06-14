#include "GoToReadingRailroadEffect.h"

void GoToReadingRailroadEffect::execute(Player& player)
{
	if (player.getCurrentPosition() > GameConstants::READING_RAILROAD_LOCATION) {
		std::cout << "You passed GO! Collect $200!";
		player.addMoney(GameConstants::PASS_GO_BONUS);
	}
	player.moveTo(GameConstants::READING_RAILROAD_LOCATION);
	std::cout << "You are currently on position " << player.getCurrentPosition() << std::endl;
}

CardEffectStrategy* GoToReadingRailroadEffect::clone() const
{
	return new GoToReadingRailroadEffect(*this);
}
