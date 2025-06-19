#pragma once
#include "Command.h"
#include "Trade.h"

class TradeCommand : public Command
{
	Trade* trade;
	void tradeProperty(Player* player, Property*& property) const;
	void tradeStation(Player* player, Station*& station) const;
	void tradeUtility(Player* player, Utility*& utility) const;
	void tradeMoney(Player* player, int& amount) const;
	void showCurrentTrade() const;
	void clearTrade() const;
public:
	TradeCommand();
	void execute() const override;
	~TradeCommand() override;
};

