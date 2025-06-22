#include "PayDebtCommand.h"

void PayDebtCommand::execute() const
{
	Player& player = game->getPlayerOnTurn();
	if (!player.isInDebt()) {
		std::cout << "You are not in debt! You can only pay if you owe money to someone!" << std::endl;
		return;
	}

	Player* creditor = player.getInDebtTo();

	if (player.getOwedMoney() <= player.getMoney()) {
		player.addMoney(-player.getOwedMoney());
		player.setInDebtStatus();
		player.setOwedMoney(0);
		std::cout << "You have successfully paid your debt of $" << player.getOwedMoney() << " to " << (creditor ? creditor->getName() : " the Bank") << "!" << std::endl;
		return;
	}

	std::cout << "You don't have enough money to pay your debt of $" << player.getOwedMoney() << " to " << (creditor ? creditor->getName() : " the Bank") << ". You can either go bankrupt or try to collect money from other players." << std::endl;
}
