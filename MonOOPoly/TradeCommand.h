#pragma once
#include "Command.h"
class TradeCommand : public Command
{
	void tradeProperty(Player* receiver) const;
	void tradeStation(Player* receiver) const;
	void tradeUtility(Player* receiver) const;
	void tradeMoney(Player* receiver) const;
public:
	TradeCommand() = default;
	void execute() const override;
};

