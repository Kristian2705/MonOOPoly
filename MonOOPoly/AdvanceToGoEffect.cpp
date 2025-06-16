#include "AdvanceToGoEffect.h"

void AdvanceToGoEffect::execute(Player& player)
{
	player.moveTo(GameConstants::GO_FIELD_INDEX);
	std::cout << "You passed GO! Collect $200!";
	player.addMoney(GameConstants::PASS_GO_BONUS);
}

CardEffectStrategy* AdvanceToGoEffect::clone() const
{
	return new AdvanceToGoEffect(*this);
}
