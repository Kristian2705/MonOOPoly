#include "PayPoorTaxEffect.h"

void PayPoorTaxEffect::execute(Player& player)
{
	if (GameConstants::POOR_TAX <= player.getMoney())
	{
		player.addMoney(-GameConstants::POOR_TAX);
	}
	else {
		//To be implemented
	}
}
