#include "Board.h"

Board::Board()
{
	initializeBoard();
}

Board* Board::instance = nullptr;

void Board::initializeBoard()
{
	fields.addElement(new GoField("<- GO Collect $200.00 salary as you pass.", "GO"));

	size_t rentTiersMA[GameConstants::RENT_TIERS_COUNT] = { 2, 4, 10, 30, 90, 160, 250 };
	fields.addElement(new Property(1, "Mediterranean Avenue", "MA", 50, rentTiersMA, 50, 50, ColorSet::Brown));

	fields.addElement(new CardField(2, "Community Chest", "CC"));

	size_t rentTiersBA[GameConstants::RENT_TIERS_COUNT] = { 4, 8, 20, 60, 180, 320, 450 };
	fields.addElement(new Property(3, "Baltic Avenue", "BA", 50, rentTiersBA, 50, 50, ColorSet::Brown));

	fields.addElement(new TaxField(4, "Income tax", "IT", 150));

	fields.addElement(new Station(5, "Reading Railroad", "RR"));

	size_t rentTiersLb[GameConstants::RENT_TIERS_COUNT] = { 6, 12, 30, 90, 270, 400, 550 };
	fields.addElement(new Property(6, "Oriental Avenue", "OA", 100, rentTiersLb, 50, 50, ColorSet::LightBlue));

	fields.addElement(new CardField(7, "Chance", "C"));

	fields.addElement(new Property(8, "Vermont Avenue", "VA", 100, rentTiersLb, 50, 50, ColorSet::LightBlue));

	size_t rentTiersCA[GameConstants::RENT_TIERS_COUNT] = { 8, 16, 40, 100, 300, 450, 600 };
	fields.addElement(new Property(9, "Connecticut Avenue", "CA", 120, rentTiersCA, 50, 50, ColorSet::LightBlue));

	fields.addElement(new JailField("Jail", "JAIL"));

	size_t rentTiersP[GameConstants::RENT_TIERS_COUNT] = { 10, 20, 50, 150, 450, 625, 750 };
	fields.addElement(new Property(11, "St. Charles Place", "StCP", 140, rentTiersP, 100, 100, ColorSet::Pink));

	fields.addElement(new Utility(12, "Electric Company", "EC"));

	fields.addElement(new Property(13, "States Avenue", "SA", 140, rentTiersP, 100, 100, ColorSet::Pink));

	size_t rentTiersViA[GameConstants::RENT_TIERS_COUNT] = { 12, 24, 60, 180, 500, 700, 900 };
	fields.addElement(new Property(14, "Virginia Avenue", "ViA", 160, rentTiersViA, 100, 100, ColorSet::Pink));

	fields.addElement(new Station(15, "Pennsylvania Railroad", "PR"));

	size_t rentTiersOr[GameConstants::RENT_TIERS_COUNT] = { 14, 28, 70, 200, 550, 750, 950 };
	fields.addElement(new Property(16, "St. James Place", "StJP", 180, rentTiersOr, 100, 100, ColorSet::Orange));

	fields.addElement(new CardField(17, "Community Chest", "CC"));

	fields.addElement(new Property(18, "Tennessee Avenue", "TenA", 180, rentTiersOr, 100, 100, ColorSet::Orange));

	size_t rentTiersNYA[GameConstants::RENT_TIERS_COUNT] = { 16, 32, 80, 220, 600, 800, 1000 };
	fields.addElement(new Property(19, "New York Avenue", "NYA", 200, rentTiersNYA, 100, 100, ColorSet::Orange));

	fields.addElement(new ParkingField("Free Parking", "FP"));

	size_t rentTiersRed[GameConstants::RENT_TIERS_COUNT] = { 18, 36, 90, 250, 700, 875, 1050 };
	fields.addElement(new Property(21, "Kentucky Avenue", "KA", 220, rentTiersRed, 150, 150, ColorSet::Red));

	fields.addElement(new CardField(22, "Chance", "C"));

	fields.addElement(new Property(23, "Indiana Avenue", "InA", 220, rentTiersRed, 150, 150, ColorSet::Red));

	size_t rentTiersIllA[GameConstants::RENT_TIERS_COUNT] = { 20, 40, 100, 300, 750, 925, 1100 };
	fields.addElement(new Property(24, "Illinois Avenue", "IllA", 240, rentTiersIllA, 150, 150, ColorSet::Red));

	fields.addElement(new Station(25, "B&O Railroad", "B&O"));

	size_t rentTiersYe[GameConstants::RENT_TIERS_COUNT] = { 22, 44, 110, 330, 800, 975, 1150 };
	fields.addElement(new Property(26, "Atlantic Avenue", "AtA", 260, rentTiersYe, 150, 150, ColorSet::Yellow));

	fields.addElement(new Property(27, "Ventnor Avenue", "VeA", 260, rentTiersYe, 150, 150, ColorSet::Yellow));

	fields.addElement(new Utility(28, "Water Works", "WW"));

	size_t rentTiersMG[GameConstants::RENT_TIERS_COUNT] = { 24, 48, 120, 360, 850, 1025, 1200 };
	fields.addElement(new Property(29, "Marvin Gardens", "MG", 280, rentTiersMG, 150, 150, ColorSet::Yellow));

	fields.addElement(new GoToJailField("Go To Jail", "GJ"));

	size_t rentTiersGr[GameConstants::RENT_TIERS_COUNT] = { 26, 52, 130, 390, 900, 1100, 1275 };
	fields.addElement(new Property(31, "Pacific Avenue", "PA", 300, rentTiersGr, 200, 200, ColorSet::Green));

	fields.addElement(new Property(32, "North Carolina Avenue", "NCA", 300, rentTiersGr, 200, 200, ColorSet::Green));

	fields.addElement(new CardField(33, "Community Chest", "CC"));

	size_t rentTiersPenA[GameConstants::RENT_TIERS_COUNT] = { 28, 56, 150, 450, 1000, 1200, 1400 };
	fields.addElement(new Property(34, "Pennsylvania Avenue", "PenA", 320, rentTiersPenA, 200, 200, ColorSet::Green));

	fields.addElement(new Station(35, "Short Line Railroad", "SLR"));

	fields.addElement(new CardField(36, "Chance", "C"));

	size_t rentTiersPP[GameConstants::RENT_TIERS_COUNT] = { 35, 70, 175, 500, 1100, 1300, 1500 };
	fields.addElement(new Property(37, "Park Place", "PP", 350, rentTiersPP, 200, 200, ColorSet::Blue));

	fields.addElement(new TaxField(38, "Luxury Tax", "LT", 100));

	size_t rentTiersBO[GameConstants::RENT_TIERS_COUNT] = { 50, 100, 200, 600, 1400, 1700, 2000 };
	fields.addElement(new Property(39, "Boardwalk", "BW", 400, rentTiersBO, 200, 200, ColorSet::Blue));
}

Board* Board::getInstance()
{
	if (!instance) {
		instance = new Board();
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

void Board::printBoard() const
{
	printTopRow();
	printMiddleRows();
	printBottomRow();
}

void Board::printCell(const MyString& label) const {
	std::cout << "|" << std::setw(GameConstants::CELL_WIDTH - 1) << std::left << label;
}

void Board::printTopRow() const {
	for (int i = 0; i < GameConstants::PRINT_BOARD_WIDTH; i++)
		printCell(fields[i]->getAbbreviation());
	std::cout << "|\n";
}

void Board::printMiddleRows() const {
	for (int i = 1; i < GameConstants::PRINT_BOARD_WIDTH - 1; ++i) {
		printCell(fields[GameConstants::BOARD_SIZE - i]->getAbbreviation());
		for (int j = 0; j < GameConstants::PRINT_BOARD_WIDTH - 2; ++j)
			std::cout << std::setw(GameConstants::CELL_WIDTH) << " ";
		printCell(fields[GameConstants::PRINT_BOARD_WIDTH + i - 1]->getAbbreviation());
		std::cout << "|\n";
	}
}

void Board::printBottomRow() const {
	for (int i = (GameConstants::PRINT_BOARD_WIDTH - 1) * 3; i >= (GameConstants::PRINT_BOARD_WIDTH - 1) * 2; --i)
		printCell(fields[i]->getAbbreviation());
	std::cout << "|\n";
}