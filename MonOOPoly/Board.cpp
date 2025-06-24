#include "Board.h"
#include "Monopoly.h"

Board::Board()
{
	initializeBoard();
}

Board* Board::instance = nullptr;

void Board::initializeBoard()
{
	fields.addElement(new GoField("<- Go", "GO"));

	size_t rentTiersMA[GameConstants::RENT_TIERS_COUNT] = { 2, 4, 10, 30, 90, 160, 250 };
	fields.addElement(new Property(1, "Mediterranean Avenue", "Mediter. Av.", 50, rentTiersMA, 50, 50, ColorSet::Brown));

	fields.addElement(new CardField(2, "Community Chest", "Chest"));

	size_t rentTiersBA[GameConstants::RENT_TIERS_COUNT] = { 4, 8, 20, 60, 180, 320, 450 };
	fields.addElement(new Property(3, "Baltic Avenue", "Baltic Av.", 50, rentTiersBA, 50, 50, ColorSet::Brown));

	fields.addElement(new TaxField(4, "Income tax", "Income tax", 150));

	fields.addElement(new Station(5, "Reading Railroad", "Reading Rail."));

	size_t rentTiersLb[GameConstants::RENT_TIERS_COUNT] = { 6, 12, 30, 90, 270, 400, 550 };
	fields.addElement(new Property(6, "Oriental Avenue", "Oriental Av.", 100, rentTiersLb, 50, 50, ColorSet::LightBlue));

	fields.addElement(new CardField(7, "Chance", "Chance"));

	fields.addElement(new Property(8, "Vermont Avenue", "Vermont Av.", 100, rentTiersLb, 50, 50, ColorSet::LightBlue));

	size_t rentTiersCA[GameConstants::RENT_TIERS_COUNT] = { 8, 16, 40, 100, 300, 450, 600 };
	fields.addElement(new Property(9, "Connecticut Avenue", "Connect. Av.", 120, rentTiersCA, 50, 50, ColorSet::LightBlue));

	fields.addElement(new JailField("Jail", "Jail"));

	size_t rentTiersP[GameConstants::RENT_TIERS_COUNT] = { 10, 20, 50, 150, 450, 625, 750 };
	fields.addElement(new Property(11, "St. Charles Place", "St. Charles P.", 140, rentTiersP, 100, 100, ColorSet::Pink));

	fields.addElement(new Utility(12, "Electric Company", "Electric comp."));

	fields.addElement(new Property(13, "States Avenue", "States Av.", 140, rentTiersP, 100, 100, ColorSet::Pink));

	size_t rentTiersViA[GameConstants::RENT_TIERS_COUNT] = { 12, 24, 60, 180, 500, 700, 900 };
	fields.addElement(new Property(14, "Virginia Avenue", "Virignia Av.", 160, rentTiersViA, 100, 100, ColorSet::Pink));

	fields.addElement(new Station(15, "Pennsylvania Railroad", "Pennsyl. Rail."));

	size_t rentTiersOr[GameConstants::RENT_TIERS_COUNT] = { 14, 28, 70, 200, 550, 750, 950 };
	fields.addElement(new Property(16, "St. James Place", "St. James P.", 180, rentTiersOr, 100, 100, ColorSet::Orange));

	fields.addElement(new CardField(17, "Community Chest", "Chest"));

	fields.addElement(new Property(18, "Tennessee Avenue", "Tennessee Av.", 180, rentTiersOr, 100, 100, ColorSet::Orange));

	size_t rentTiersNYA[GameConstants::RENT_TIERS_COUNT] = { 16, 32, 80, 220, 600, 800, 1000 };
	fields.addElement(new Property(19, "New York Avenue", "New York Av.", 200, rentTiersNYA, 100, 100, ColorSet::Orange));

	fields.addElement(new ParkingField("Free Parking", "Free Parking"));

	size_t rentTiersRed[GameConstants::RENT_TIERS_COUNT] = { 18, 36, 90, 250, 700, 875, 1050 };
	fields.addElement(new Property(21, "Kentucky Avenue", "Kentucky Av.", 220, rentTiersRed, 150, 150, ColorSet::Red));

	fields.addElement(new CardField(22, "Chance", "Chance"));

	fields.addElement(new Property(23, "Indiana Avenue", "Indiana Av.", 220, rentTiersRed, 150, 150, ColorSet::Red));

	size_t rentTiersIllA[GameConstants::RENT_TIERS_COUNT] = { 20, 40, 100, 300, 750, 925, 1100 };
	fields.addElement(new Property(24, "Illinois Avenue", "Illinois Av.", 240, rentTiersIllA, 150, 150, ColorSet::Red));

	fields.addElement(new Station(25, "B&O Railroad", "B&O Rail."));

	size_t rentTiersYe[GameConstants::RENT_TIERS_COUNT] = { 22, 44, 110, 330, 800, 975, 1150 };
	fields.addElement(new Property(26, "Atlantic Avenue", "Atlantic Av.", 260, rentTiersYe, 150, 150, ColorSet::Yellow));

	fields.addElement(new Property(27, "Ventnor Avenue", "Ventnor Av.", 260, rentTiersYe, 150, 150, ColorSet::Yellow));

	fields.addElement(new Utility(28, "Water Works", "Water Works"));

	size_t rentTiersMG[GameConstants::RENT_TIERS_COUNT] = { 24, 48, 120, 360, 850, 1025, 1200 };
	fields.addElement(new Property(29, "Marvin Gardens", "Marvin Gardens", 280, rentTiersMG, 150, 150, ColorSet::Yellow));

	fields.addElement(new GoToJailField("Go To Jail", "Go To Jail"));

	size_t rentTiersGr[GameConstants::RENT_TIERS_COUNT] = { 26, 52, 130, 390, 900, 1100, 1275 };
	fields.addElement(new Property(31, "Pacific Avenue", "Pacific Av.", 300, rentTiersGr, 200, 200, ColorSet::Green));

	fields.addElement(new Property(32, "North Carolina Avenue", "North Car. Av.", 300, rentTiersGr, 200, 200, ColorSet::Green));

	fields.addElement(new CardField(33, "Chest", "Chest"));

	size_t rentTiersPenA[GameConstants::RENT_TIERS_COUNT] = { 28, 56, 150, 450, 1000, 1200, 1400 };
	fields.addElement(new Property(34, "Pennsylvania Avenue", "Pennsyl. Av.", 320, rentTiersPenA, 200, 200, ColorSet::Green));

	fields.addElement(new Station(35, "Short Line Railroad", "Sh. Line Rail."));

	fields.addElement(new CardField(36, "Chance", "Chance"));

	size_t rentTiersPP[GameConstants::RENT_TIERS_COUNT] = { 35, 70, 175, 500, 1100, 1300, 1500 };
	fields.addElement(new Property(37, "Park Place", "Park Place", 350, rentTiersPP, 200, 200, ColorSet::Blue));

	fields.addElement(new TaxField(38, "Luxury Tax", "Luxury Tax", 100));

	size_t rentTiersBO[GameConstants::RENT_TIERS_COUNT] = { 50, 100, 200, 600, 1400, 1700, 2000 };
	fields.addElement(new Property(39, "Boardwalk", "Boardwalk", 400, rentTiersBO, 200, 200, ColorSet::Blue));
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

void Board::printBoard() const
{
	printTopRow();
	printMiddleRows();
	printBottomRow();
}

void Board::stepOn(size_t position, Player& player)
{
	fields[position]->applyEffect(player);
}

void Board::printCell(const MyString& label) const {
	std::cout << std::setw(17 - 1) << std::left << label << " |";
}

void Board::printTopRow() const {
	const MyVector<Player>& players = Monopoly::getInstance()->getPlayers();

	for (int i = 0; i < GameConstants::PRINT_BOARD_WIDTH; i++) {
		std::cout << std::setw(18) << "------------------";
	}

	std::cout << "\n";

	for (int i = 0; i < GameConstants::PRINT_BOARD_WIDTH; i++)
		printCell(fields[i]->getAbbreviation());
	std::cout << "\n";

	for (int i = 0; i < GameConstants::PRINT_BOARD_WIDTH; i++) {
		MyString playerStr = "";
		for(int j = 0; j < players.getSize(); j++) {
			if (players[j].getCurrentPosition() == i) {
				playerStr += "P";
				playerStr += MyString::itos(players[j].getId());
				if (j != players.getSize() - 1) {
					playerStr += " ";
				}
			}
		}
		std::cout << std::setw(17) << std::left << playerStr << "|";
	}

	std::cout << "\n";

	for (int i = 0; i < GameConstants::PRINT_BOARD_WIDTH; i++) {
		std::cout << std::setw(18) << "------------------";
	}

	std::cout << "\n";
}

void Board::printMiddleRows() const {
	const MyVector<Player>& players = Monopoly::getInstance()->getPlayers();

	for (int i = 1; i < GameConstants::PRINT_BOARD_WIDTH - 1; i++) {
		printCell(fields[GameConstants::BOARD_SIZE - i]->getAbbreviation());

		for (int j = 0; j < GameConstants::PRINT_BOARD_WIDTH - 2; j++) {
			if (j == GameConstants::PRINT_BOARD_WIDTH - 3) {
				std::cout << std::setw(17) << " ";
				std::cout << "|";
				continue;
			}
			std::cout << std::setw(18) << " ";
		}

		printCell(fields[GameConstants::PRINT_BOARD_WIDTH + i - 1]->getAbbreviation());

		std::cout << "\n";

		for (int j = 0; j < GameConstants::PRINT_BOARD_WIDTH; j++) {
			if (j == 0) {
				MyString playerStr = "";
				for (int k = 0; k < players.getSize(); k++) {
					if (players[k].getCurrentPosition() == GameConstants::BOARD_SIZE - i) {
						playerStr += "P";
						playerStr += MyString::itos(players[k].getId());
						if (k != players.getSize() - 1) {
							playerStr += " ";
						}
					}
				}
				std::cout << std::setw(17) << std::left << playerStr << "|";
				continue;
			}
			if(j == GameConstants::PRINT_BOARD_WIDTH - 2) {
				std::cout << std::setw(17) << " ";
				continue;
			}
			if (j == GameConstants::PRINT_BOARD_WIDTH - 1) {
				std::cout << "|";
				MyString playerStr = "";
				for (int k = 0; k < players.getSize(); k++) {
					if (players[k].getCurrentPosition() == GameConstants::PRINT_BOARD_WIDTH + i - 1) {
						playerStr += "P";
						playerStr += MyString::itos(players[k].getId());
						if (k != players.getSize() - 1) {
							playerStr += " ";
						}
					}
				}
				std::cout << std::setw(17) << std::left << playerStr << "|";
				continue;
			}
			std::cout << std::setw(18) << " ";
		}

		std::cout << "\n";

		if (i == GameConstants::PRINT_BOARD_WIDTH - 2) {
			continue;
		}

		for (int j = 0; j < GameConstants::PRINT_BOARD_WIDTH; j++) {
			if (j == 0) {
				std::cout << std::setw(18) << "------------------";
				continue;
			}
			if (j == GameConstants::PRINT_BOARD_WIDTH - 1) {
				std::cout << std::setw(18) << "-------------------";
				continue;
			}
			if (j == GameConstants::PRINT_BOARD_WIDTH - 2) {
				std::cout << std::setw(17) << " ";
				continue;
			}
			std::cout << std::setw(18) << " ";
		}
		std::cout << "\n";
	}
}

void Board::printBottomRow() const {
	const MyVector<Player>& players = Monopoly::getInstance()->getPlayers();

	for (int i = 0; i < GameConstants::PRINT_BOARD_WIDTH; i++) {
		std::cout << std::setw(18) << "------------------";
	}

	std::cout << "\n";

	for (int i = (GameConstants::PRINT_BOARD_WIDTH - 1) * 3; i >= (GameConstants::PRINT_BOARD_WIDTH - 1) * 2; i--)
		printCell(fields[i]->getAbbreviation());

	std::cout << "\n";

	for (int i = 0; i < GameConstants::PRINT_BOARD_WIDTH; i++) {
		MyString playerStr = "";
		for (int j = 0; j < players.getSize(); j++) {
			if (players[j].getCurrentPosition() == (GameConstants::PRINT_BOARD_WIDTH - 1) * 3 - i) {
				playerStr += "P";
				playerStr += MyString::itos(players[j].getId());
				if (j != players.getSize() - 1) {
					playerStr += " ";
				}
			}
		}
		std::cout << std::setw(17) << std::left << playerStr << "|";
	}

	std::cout << "\n";

	for (int i = 0; i < GameConstants::PRINT_BOARD_WIDTH; i++) {
		std::cout << std::setw(18) << "------------------";
	}

	std::cout << "\n";
}

void Board::saveToBinary(std::ofstream& ofs) const
{
	if (!ofs.is_open()) {
		throw std::runtime_error("Error opening file for saving board data.");
	}
	for (int i = 0; i < GameConstants::BOARD_SIZE; i++) {
		fields[i]->saveToBinary(ofs);
	}
}

void Board::loadFromBinary(std::ifstream& ifs)
{
	if (!ifs.is_open()) {
		throw std::runtime_error("Error opening file for loading board data.");
	}
	for (int i = 0; i < GameConstants::BOARD_SIZE; i++) {
		fields[i]->loadFromBinary(ifs);
	}
}