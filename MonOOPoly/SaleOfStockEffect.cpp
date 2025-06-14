#include "SaleOfStockEffect.h"

void SaleOfStockEffect::execute(Player& player)
{
	player.addMoney(GameConstants::SALE_OF_STOCK_REWARD);
}

CardEffectStrategy* SaleOfStockEffect::clone() const
{
	return new SaleOfStockEffect(*this);
}
