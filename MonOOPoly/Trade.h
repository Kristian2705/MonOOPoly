#pragma once
#include "Property.h"
#include "Station.h"
#include "Utility.h"

class Player;

class Trade
{
	Player* sender = nullptr;
	Player* receiver = nullptr;

	Property* propertyToGet = nullptr;
	Property* propertyToGive = nullptr;

	Station* stationToGet = nullptr;
	Station* stationToGive = nullptr;

	Utility* utilityToGet = nullptr;
	Utility* utilityToGive = nullptr;

	int moneyToGet = 0;
	int moneyToGive = 0;
public:
	Trade() = default;

	void show() const;
	void clear();
	void initiate();

	friend class TradeCommand;
};

