#include "TaxField.h"
#include "Monopoly.h"

TaxField::TaxField(int boardIndex, const MyString& name, const MyString& abbreviation, int taxAmount)
	: Field(boardIndex, name, abbreviation), taxAmount(taxAmount)
{ }

void TaxField::applyEffect(Player& player)
{
	if (taxAmount <= player.getMoney()) {
		player.addMoney(-taxAmount);
		std::cout << "You successfully paid the tax of $" << taxAmount << std::endl;
		std::cout << "You currently have $" << player.getMoney() << std::endl;
		return;
	}
	player.setInDebtStatus();
	std::cout << "You don't have enough money to pay your debt to the bank." << std::endl;
	std::cout << "You owe $" << taxAmount << " but you have $" << player.getMoney() << std::endl;
	std::cout << "Find a way to collect the money or go bankrupt." << std::endl;
}

Field* TaxField::clone() const
{
	return new TaxField(*this);
}


