#include "CardDeck.h"
#include "ReceivePaymentEffect.h"
#include "RepairEffect.h"
#include "FeeEffect.h"
#include "MultiplePaymentEffect.h"
#include "AdvanceToGoEffect.h"
#include "GoBackThreeSpacesEffect.h"
#include "GetOutOfJailEffect.h"
#include "GoToJailEffect.h"
#include "GoToLocationEffect.h"
#include "GoToNearestRailroadEffect.h"
#include "GoToNearestUtilityEffect.h"
#include "MultiplePaymentToOthers.h"

CardDeck::CardDeck() 
{
	loadCards();
}

CardDeck* CardDeck::instance = nullptr;

void CardDeck::loadCards()
{
	//CC 17
	cards.push_back(new Card("Advance to \"Go\". (Collect $200)",
		std::make_unique<AdvanceToGoEffect>()));

	cards.push_back(new Card("You are assessed for street repairs: Pay $40 per house and $115 per hotel you own",
		std::make_unique<RepairEffect>(GameConstants::ASSESSED_HOUSE_REPAIR_PRICE, GameConstants::ASSESSED_HOTEL_REPAIR_PRICE)));

	cards.push_back(new Card("Bank error in your favor. Collect $200.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::BANK_ERROR_REWARD)));

	cards.push_back(new Card("Receive $25 consultancy fee.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::CONSULTANCY_FEE_REWARD)));

	cards.push_back(new Card("Get out of Jail Free. This card may be kept until needed, or traded/sold.",
		std::make_unique<GetOutOfJailEffect>()));

	cards.push_back(new Card("Go to Jail. Go directly to Jail. Do not pass GO, do not collect $200.",
		std::make_unique<GoToJailEffect>()));

	cards.push_back(new Card("Doctor's fees. Pay $50.",
		std::make_unique<FeeEffect>(GameConstants::DOCTOR_FEE)));

	cards.push_back(new Card("Holiday Fund matures. Receive $100.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::HOLIDAY_FUNDS_REWARD)));

	cards.push_back(new Card("Hospital Fees. Pay $50.", 
		std::make_unique<FeeEffect>(GameConstants::HOSPITAL_FEE)));

	cards.push_back(new Card("Income tax refund. Collect $20.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::INCOME_TAX_REFUND)));

	cards.push_back(new Card("You inherit $100.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::INHERITANCE_REWARD)));

	cards.push_back(new Card("Life insurance matures – Collect $100.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::LIFE_INSURANCE)));


	cards.push_back(new Card("From sale of stock you get $50.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::SALE_OF_STOCK_REWARD)));

	cards.push_back(new Card("School fees. Pay $50.",
		std::make_unique<FeeEffect>(GameConstants::SCHOOL_FEE)));

	cards.push_back(new Card("You have won second prize in a beauty contest. Collect $10.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::BEAUTY_CONTEST_REWARD)));

	cards.push_back(new Card("Grand Opera Night. Collect $50 from every player for opening night seats.",
		std::make_unique<MultiplePaymentEffect>(GameConstants::GRAND_OPERA_NIGHT_REWARD)));

	cards.push_back(new Card("It is your birthday. Collect $10 from every player.",
		std::make_unique<MultiplePaymentEffect>(GameConstants::BIRTHDAY_REWARD)));

	//Chance 15
	cards.push_back(new Card("Advance to \"Go\". (Collect $200)",
		std::make_unique<AdvanceToGoEffect>()));

	cards.push_back(new Card("Advance to Illinois Ave. If you pass Go, collect $200.",
		std::make_unique<GoToLocationEffect>(GameConstants::ILLINOIS_LOCATION)));

	cards.push_back(new Card("Advance to St. Charles Place. If you pass Go, collect $200.",
		std::make_unique<GoToLocationEffect>(GameConstants::ST_CHARLES_LOCATION)));

	cards.push_back(new Card("Advance token to the nearest Utility. If unowned, you may buy it from the Bank. If owned, throw dice and pay owner a total 10 times the amount thrown.",
		std::make_unique<GoToNearestUtilityEffect>()));

	cards.push_back(new Card("Advance to the nearest Railroad. If unowned, you may buy it from the Bank. If owned, pay owner twice the rent to which they are otherwise entitled.",
		std::make_unique<GoToNearestRailroadEffect>()));

	cards.push_back(new Card("Get out of Jail Free. This card may be kept until needed, or traded/sold.",
		std::make_unique<GetOutOfJailEffect>()));

	cards.push_back(new Card("Go to Jail. Go directly to Jail. Do not pass GO, do not collect $200.",
		std::make_unique<GoToJailEffect>()));

	cards.push_back(new Card("Go Back Three Spaces.",
		std::make_unique<GoBackThreeSpacesEffect>()));

	cards.push_back(new Card("Take a trip to Reading Railroad. If you pass Go, collect $200.",
		std::make_unique<GoToLocationEffect>(GameConstants::READING_RAILROAD_LOCATION)));

	cards.push_back(new Card("Take a walk on the Boardwalk. Advance token to Boardwalk.",
		std::make_unique<GoToLocationEffect>(GameConstants::BROADWALK_LOCATION)));

	cards.push_back(new Card("Pay Poor Tax of $15.",
		std::make_unique<FeeEffect>(GameConstants::POOR_TAX)));

	cards.push_back(new Card("You have been elected Chairman of the Board. Pay each player $50.",
		std::make_unique<MultiplePaymentToOthers>(GameConstants::CHAIRMAN_OF_THE_BOARD_AMOUNT)));

	cards.push_back(new Card("Your building loan matures. Receive $150.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::LOAN_MATURES_REWARD)));

	cards.push_back(new Card("Make general repairs on all your property: For each house pay $25, For each hotel $100. ",
		std::make_unique<RepairEffect>(GameConstants::REPAIR_HOUSE_PRICE, GameConstants::REPAIR_HOTEL_PRICE)));

	cards.push_back(new Card("Bank pays you dividend of $50",
		std::make_unique<ReceivePaymentEffect>(GameConstants::BANK_DIVIDENT_REWARD)));

	shuffleDeck();
}

CardDeck* CardDeck::getInstance()
{
	if (!instance)
	{
		instance = new CardDeck();
	}

	return instance;
}

void CardDeck::freeInstance()
{
	delete instance;
	instance = nullptr;
}

void CardDeck::showCards()
{
	for (int i = 0; i < cards.getSize(); i++) {
		std::cout << cards[i]->getDescription() << std::endl;
	}
}

Card* CardDeck::drawCard()
{
	Card* card = cards[0];
	if (!card) {
		throw new std::invalid_argument("No cards in the deck to draw.");
	}
	return card;
}

void CardDeck::shuffleDeck()
{
	srand(time(NULL));
	int n = cards.getSize();
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		cards.swap(i, j);
	}
}
