#include "PayDebtCommand.h"

void PayDebtCommand::execute() const
{
	Player& player = game->getPlayerOnTurn();
	if (!player.isInDebt()) {
		throw std::invalid_argument("You are not in debt! You can only pay if you owe money to someone!");
	}

	Player* creditor = player.getInDebtTo();

	if (player.getOwedMoney() <= player.getMoney()) {
		player.addMoney(-player.getOwedMoney());
		player.setInDebtStatus();
		if (creditor) {
			creditor->addMoney(player.getOwedMoney());
		}
		std::cout << "You have successfully paid your debt of $" << player.getOwedMoney() << " to " << (creditor ? creditor->getName() : "the Bank") << "!" << std::endl;
		player.setOwedMoney(0);
		return;
	}

	std::cout << "You don't have enough money to pay your debt of $" << player.getOwedMoney() << " to " << (creditor ? creditor->getName() : "the Bank") << ". You can either go bankrupt or try to collect money from other players." << std::endl;
}
