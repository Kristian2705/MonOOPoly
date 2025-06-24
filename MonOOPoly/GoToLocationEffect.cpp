#include "GoToLocationEffect.h"

GoToLocationEffect::GoToLocationEffect(size_t locationIndex)
	: locationIndex(locationIndex)
{ }

void GoToLocationEffect::execute(Player& player)
{
	player.moveTo(locationIndex);
}
