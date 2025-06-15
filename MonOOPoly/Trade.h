#pragma once
#include "MyVector.hpp"
#include "Property.h"

class Trade
{
	MyVector<Property*> offeredProperties;
	MyString firstPersonMessage;
	MyString secondPersonMessage;
	int price;
};

