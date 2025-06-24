#include "GoToJailEffect.h"

void GoToJailEffect::execute(Player& player)
{
	player.setJailStatus();
}
