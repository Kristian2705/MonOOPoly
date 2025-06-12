#include "Board.h"

Board::Board()
{
	//load default data
}

Board* Board::instance = nullptr;

void Board::initializeBoard()
{
	fields.addElement(new GoField("<- GO Collect $200.00 salary as you pass."));

	size_t rentTiersMA[GameConstants::RENT_TIERS_COUNT] = { 2, 4, 10, 30, 90, 160, 250 };
	fields.addElement(new Property(1, "Mediterranean Avenue", 50, rentTiersMA, 50, 50, ColorSet::Brown));

	fields.addElement(new CardField(2, "Community Chest"));

	size_t rentTiersBA[GameConstants::RENT_TIERS_COUNT] = { 4, 8, 20, 60, 180, 320, 450 };
	fields.addElement(new Property(3, "Baltic Avenue", 50, rentTiersMA, 50, 50, ColorSet::Brown));

	fields.addElement(new TaxField(4, "Income tax", 150));

	fields.addElement(new Station(5, "Reading Railroad"));

	size_t rentTiersOA[GameConstants::RENT_TIERS_COUNT] = { 6, 12, 30, 90, 270, 400, 550 };
	fields.addElement(new Property(6, "Oriental Avenue", 100, rentTiersMA, 50, 50, ColorSet::LightBlue));

	fields.addElement(new CardField(7, "Chance"));

	size_t rentTiersVA[GameConstants::RENT_TIERS_COUNT] = { 6, 12, 30, 90, 270, 400, 550 };
	fields.addElement(new Property(8, "Vermont Avenue", 100, rentTiersMA, 50, 50, ColorSet::LightBlue));

	size_t rentTiersCA[GameConstants::RENT_TIERS_COUNT] = { 8, 16, 40, 100, 300, 450, 600 };
	fields.addElement(new Property(9, "Connecticut Avenue", 120, rentTiersMA, 50, 50, ColorSet::LightBlue));

	fields.addElement(new JailField("Jail"));

	size_t rentTiersSA[GameConstants::RENT_TIERS_COUNT] = { 10, 20, 50, 150, 450, 625, 750 };
	fields.addElement(new Property(11, "St. Charles Place", 140, rentTiersSA, 100, 100, ColorSet::Pink));

	fields.addElement(new Utility(12, "Electric Company"));

	size_t rentTiersAA[GameConstants::RENT_TIERS_COUNT] = { 10, 20, 50, 150, 450, 625, 750 };
	fields.addElement(new Property(13, "States Avenue", 140, rentTiersAA, 100, 100, ColorSet::Pink));

	size_t rentTiersViA[GameConstants::RENT_TIERS_COUNT] = { 12, 24, 60, 180, 500, 700, 900 };
	fields.addElement(new Property(14, "Virginia Avenue", 160, rentTiersViA, 100, 100, ColorSet::Pink));

	fields.addElement(new Station(15, "Pennsylvania Railroad"));

	size_t rentTiersStA[GameConstants::RENT_TIERS_COUNT] = { 14, 28, 70, 200, 550, 750, 950 };
	fields.addElement(new Property(16, "St. James Place", 180, rentTiersStA, 100, 100, ColorSet::Orange));

	fields.addElement(new CardField(17, "Community Chest"));

	size_t rentTiersTenA[GameConstants::RENT_TIERS_COUNT] = { 14, 28, 70, 200, 550, 750, 950 };
	fields.addElement(new Property(18, "Tennessee Avenue", 180, rentTiersTenA, 100, 100, ColorSet::Orange));

	size_t rentTiersNYA[GameConstants::RENT_TIERS_COUNT] = { 16, 32, 80, 220, 600, 800, 1000 };
	fields.addElement(new Property(19, "New York Avenue", 200, rentTiersNYA, 100, 100, ColorSet::Orange));

	fields.addElement(new ParkingField("Free Parking"));

	size_t rentTiersKA[GameConstants::RENT_TIERS_COUNT] = { 18, 36, 90, 250, 700, 875, 1050 };
	fields.addElement(new Property(21, "Kentucky Avenue", 220, rentTiersNYA, 150, 150, ColorSet::Red));

	fields.addElement(new CardField(22, "Chance"));

	size_t rentTiersIA[GameConstants::RENT_TIERS_COUNT] = { 18, 36, 90, 250, 700, 875, 1050 };
	fields.addElement(new Property(23, "Indiana Avenue", 220, rentTiersIA, 150, 150, ColorSet::Red));

	size_t rentTiersIllA[GameConstants::RENT_TIERS_COUNT] = { 20, 40, 100, 300, 750, 925, 1100 };
	fields.addElement(new Property(24, "Illinois Avenue", 240, rentTiersIllA, 150, 150, ColorSet::Red));

	fields.addElement(new Station(25, "B&O Railroad"));

	size_t rentTiersAtA[GameConstants::RENT_TIERS_COUNT] = { 22, 44, 110, 330, 800, 975, 1150 };
	fields.addElement(new Property(26, "Atlantic Avenue", 260, rentTiersAtA, 150, 150, ColorSet::Yellow));
	
	size_t rentTiersVeA[GameConstants::RENT_TIERS_COUNT] = { 22, 44, 110, 330, 800, 975, 1150 };
	fields.addElement(new Property(27, "Ventnor Avenue", 260, rentTiersVeA, 150, 150, ColorSet::Yellow));
	
	fields.addElement(new Utility(28, "Water Works"));

	size_t rentTiersMG[GameConstants::RENT_TIERS_COUNT] = { 24, 48, 120, 360, 850, 1025, 1200 };
	fields.addElement(new Property(29, "Marvin Gardens", 280, rentTiersMG, 150, 150, ColorSet::Yellow));

	fields.addElement(new GoToJailField("Go To Jail"));

	size_t rentTiersPA[GameConstants::RENT_TIERS_COUNT] = { 26, 52, 130, 390, 900, 1100, 1275 };
	fields.addElement(new Property(31, "Pacific Avenue", 300, rentTiersPA, 200, 200, ColorSet::Green));

	size_t rentTiersNCA[GameConstants::RENT_TIERS_COUNT] = { 26, 52, 130, 390, 900, 1100, 1275 };
	fields.addElement(new Property(32, "North Carolina Avenue", 300, rentTiersNCA, 200, 200, ColorSet::Green));

	fields.addElement(new CardField(33, "Community Chest"));

	size_t rentTiersPenA[GameConstants::RENT_TIERS_COUNT] = { 28, 56, 150, 450, 1000, 1200, 1400 };
	fields.addElement(new Property(34, "Pennsylvania Avenue", 320, rentTiersPenA, 200, 200, ColorSet::Green));

	fields.addElement(new Station(35, "Short Line Railroad"));

	fields.addElement(new CardField(36, "Chance"));

	size_t rentTiersPP[GameConstants::RENT_TIERS_COUNT] = { 35, 70, 175, 500, 1100, 1300, 1500 };
	fields.addElement(new Property(37, "Park Place", 350, rentTiersPP, 200, 200, ColorSet::Blue));

	fields.addElement(new TaxField(38, "Luxury Tax", 100));

	size_t rentTiersBO[GameConstants::RENT_TIERS_COUNT] = { 50, 100, 200, 600, 1400, 1700, 2000 };
	fields.addElement(new Property(39, "Boardwalk", 400, rentTiersBO, 200, 200, ColorSet::Blue));
}

Board* Board::getInstance()
{
    if (!instance) {
		instance = new Board();
		instance->initializeBoard();
    }
	return instance;
}

void Board::freeInstance()
{
	delete instance;
	instance = nullptr;
}

void Board::addPlayer(const Player& player)
{
	players.push_back(player);
}

const Player& Board::getPlayer(int playerId) const
{
	for (int i = 0; i < players.getSize(); i++)
	{
		if (players[i].getId() == playerId)
		{
			return players[i];
		}
	}
	throw std::out_of_range("Player not found");
}

Player& Board::getPlayer(int playerId)
{
	for (int i = 0; i < players.getSize(); i++)
	{
		if (players[i].getId() == playerId)
		{
			return players[i];
		}
	}
	throw std::out_of_range("Player not found");
}
