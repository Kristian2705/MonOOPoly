#pragma once
#include "Monopoly.h"
class Command
{
protected:
	Monopoly* game;
public:
	Command();
	virtual void execute() const = 0;
	virtual ~Command() = default;
};

