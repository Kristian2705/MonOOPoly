#include "CardDeck.h"
#include "ReceivePaymentEffect.h"
#include "RepairEffect.h"
#include "FeeEffect.h"
#include "MultiplePaymentEffect.h"

CardDeck::CardDeck() { }

CardDeck* CardDeck::instance = nullptr;

void CardDeck::loadCards()
{
	cards.push_back(new Card("You are assessed for street repairs: Pay $40 per house and $115 per hotel you own",
		std::make_unique<RepairEffect>(GameConstants::ASSESSED_HOUSE_REPAIR_PRICE, GameConstants::ASSESSED_HOTEL_REPAIR_PRICE)));

	cards.push_back(new Card("Bank error in your favor. Collect $200.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::BANK_ERROR_REWARD)));

	cards.push_back(new Card("Bank pays you dividend of $50",
		std::make_unique<ReceivePaymentEffect>(GameConstants::BANK_DIVIDENT_REWARD)));

	cards.push_back(new Card("Receive $25 consultancy fee.",
		std::make_unique<ReceivePaymentEffect>(GameConstants::CONSULTANCY_FEE_REWARD)));

	cards.push_back(new Card("Doctor's fees. Pay $50.",
		std::make_unique<FeeEffect>(GameConstants::DOCTOR_FEE)));

	cards.push_back(new Card("Make general repairs on all your property: For each house pay $25, For each hotel $100. ",
		std::make_unique<RepairEffect>(GameConstants::REPAIR_HOUSE_PRICE, GameConstants::REPAIR_HOTEL_PRICE)));

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

	cards.push_back(new Card("Pay Poor Tax of $15.",
		std::make_unique<FeeEffect>(GameConstants::POOR_TAX)));

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
}

CardDeck* CardDeck::getInstance()
{
	if (!instance)
	{
		instance = new CardDeck();
		instance->shuffleDeck();
	}

	return instance;
}

void CardDeck::freeInstance()
{
	delete instance;
	instance = nullptr;
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
