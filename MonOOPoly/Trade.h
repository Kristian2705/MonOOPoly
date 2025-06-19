#pragma once
#include "Property.h"
#include "Station.h"
#include "Utility.h"

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

	int moneyToGet;
	int moneyToGive;
public:
	Trade() = default;

	void showTrade() const;
};

