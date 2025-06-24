#include "GetOutOfJailEffect.h"

void GetOutOfJailEffect::execute(Player& player)
{
	player.addReleaseCard();
}
