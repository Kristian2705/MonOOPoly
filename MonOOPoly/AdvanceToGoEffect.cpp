#include "AdvanceToGoEffect.h"

void AdvanceToGoEffect::execute(Player& player)
{
	player.moveTo(GameConstants::GO_FIELD_INDEX);
}

CardEffectStrategy* AdvanceToGoEffect::clone() const
{
	return new AdvanceToGoEffect(*this);
}
