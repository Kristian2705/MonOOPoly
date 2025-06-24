#include "Player.h"
#include "Card.h"
#include "Monopoly.h"

int Player::nextId = 1;

Player::Player(const MyString& name, int money)
	: id(nextId++), name(name), money(money), position(GameConstants::GO_FIELD_INDEX)
{
	this->ownedProperties = MyVector<Property*>(GameConstants::MIN_CAPACITY);
	this->ownedStations = MyVector<Station*>(GameConstants::MIN_CAPACITY);
	this->ownedUtilities = MyVector<Utility*>(GameConstants::MIN_CAPACITY);
}

Player::Player(int id, const MyString& name, int money, int owedMoney, size_t position, 
	bool inJail, bool isInDebt, int timesLeftToRollInJail, int releaseCards, Player* inDebtTo, 
	const MyVector<Property*>& properties, const MyVector<Station*>& stations, const MyVector<Utility*>& utilities)
	: id(id), name(name), money(money), owedMoney(owedMoney), position(position),
	  inJail(inJail), inDebt(isInDebt), timesLeftToRollInJail(timesLeftToRollInJail), releaseCards(releaseCards),
	inDebtTo(inDebtTo), ownedProperties(properties), ownedStations(stations), ownedUtilities(utilities)
{ }

int Player::getId() const
{
	return this->id;
}

int Player::getMoney() const
{
	return money;
}

int Player::getOwedMoney() const
{
	return owedMoney;
}

void Player::addProperty(Property* property)
{
	ownedProperties.push_back(property);
	property->setOwner(this);

	std::cout << name << ", " << property->getName() << " is now yours!" << std::endl;

	//std::cout << "You successfully purchased " << property->getName() << " for $" << property->getPrice() << std::endl;

	MyVector<Property*> propsByColor;
	for (int i = 0; i < ownedProperties.getSize(); i++) {
		if (property->getColorSet() == ownedProperties[i]->getColorSet()) {
			propsByColor.push_back(ownedProperties[i]);
		}
	}

	switch (property->getColorSet())
	{
		case ColorSet::Brown:
		case ColorSet::Blue:
			if (propsByColor.getSize() == GameConstants::FIRST_AND_LAST_PROPERTIES_COUNT_BY_COLOR) {
				for (int i = 0; i < propsByColor.getSize(); i++) {
					propsByColor[i]->increaseRentTier();
				}
				std::cout << "You have collected all properties of color " << (int)property->getColorSet() << std::endl;
				std::cout << "You can now build houses and later hotels on the properties of this color to increase the rent!" << std::endl;
			}
			break;
		default:
			if (propsByColor.getSize() == GameConstants::REST_PROPERTIES_COUNT_BY_COLOR_) {
				for (int i = 0; i < propsByColor.getSize(); i++) {
					propsByColor[i]->increaseRentTier();
				}
				std::cout << "You have collected all properties of color " << (int)property->getColorSet() << std::endl;
				std::cout << "You can now build houses and later hotels on the properties of this color to increase the rent!" << std::endl;
			}
			break;
	}
}

void Player::addStation(Station* station)
{
	ownedStations.push_back(station);
	station->setOwner(this);
	std::cout << name << ", " << station->getName() << " is now yours!" << std::endl;
	//std::cout << "You successfully purchased " << station->getName() << " for $" << station->getPrice() << std::endl;
	int ownedStationsCount = ownedStations.getSize();
	if (ownedStationsCount > 1) {
		station->setRentTier(ownedStations[0]->getRentTierIndex());
		for (int i = 0; i < ownedStationsCount; i++) {
			ownedStations[i]->increaseRentTier();
		}
	}
	std::cout << "You currently have " << ownedStationsCount << " stations. Their rent is $" << station->getRent() << std::endl;
}

void Player::addReleaseCard()
{
	releaseCards++;
}

void Player::removeReleaseCard()
{
	releaseCards--;
}

void Player::addUtility(Utility* utility)
{
	ownedUtilities.push_back(utility);
	utility->setOwner(this);
	std::cout << name << ", " << utility->getName() << " is now yours!" << std::endl;
	//std::cout << "You successfully purchased " << utility->getName() << " for $" << utility->getPrice() << std::endl;
	int ownedUtilitiesCount = ownedUtilities.getSize();
	if (ownedUtilitiesCount > 1) {
		for (int i = 0; i < ownedUtilitiesCount; i++) {
			ownedUtilities[i]->increaseRentMultiplier();
		}
	}
	std::cout << "You currently have " << ownedUtilitiesCount << " utilities. Their rent multiplier is " << utility->getRentMultiplier() << "x" << std::endl;
}

void Player::addMoney(int amount)
{
	money += amount;
}

const MyString& Player::getName() const
{
	return name;
}


void Player::removeProperty(Property* property)
{
	int index = -1;
	for (int i = 0; i < ownedProperties.getSize(); i++) {
		if (property == ownedProperties[i]) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		throw std::invalid_argument("Invalid index for removal of properties!");
	}

	ownedProperties.erase(index);
}

void Player::removeStation(Station* station)
{
	int index = -1;
	for (int i = 0; i < ownedStations.getSize(); i++) {
		if (station == ownedStations[i]) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		throw std::invalid_argument("Invalid index for removal of stations!");
	}

	ownedStations.erase(index);
}

void Player::removeUtility(Utility* utility)
{
	int index = -1;
	for (int i = 0; i < ownedUtilities.getSize(); i++) {
		if (utility == ownedUtilities[i]) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		throw std::invalid_argument("Invalid index for removal of utilities!");
	}

	ownedUtilities.erase(index);
}

void Player::decreaseTimesLeft()
{
	timesLeftToRollInJail--;
}

void Player::setJailStatus()
{
	inJail = !inJail;
	if (inJail)
	{
		position = GameConstants::JAIL_POSITION;
	}
	else {
		timesLeftToRollInJail = GameConstants::TIMES_TO_ROLL_IN_JAIL;
	}
}

void Player::setInDebtStatus()
{
	inDebt = !inDebt;
	if (!inDebt) {
		inDebtTo = nullptr;
		std::cout << "You are no longer in debt." << std::endl;
	}
}

void Player::setInDebtTo(Player* player)
{
	inDebtTo = player;
	std::cout << "You are now in debt to " << player->getName() << std::endl;
}

void Player::setOwedMoney(int amount)
{
	owedMoney = amount;
}

void Player::resign()
{
	inGame = false;
	position = GameConstants::GO_FIELD_INDEX;
	inJail = false;
	inDebt = false;
	owedMoney = 0;
	timesLeftToRollInJail = 0;
	if (inDebtTo) {
		for(int i = 0; i < ownedProperties.getSize(); i++) {
			ownedProperties[i]->removeOwner();
			ownedProperties[i]->resetRentTier();
			ownedProperties[i]->setOwner(inDebtTo);
			inDebtTo->addProperty(ownedProperties[i]);
		}
		for(int i = 0; i < ownedStations.getSize(); i++) {
			ownedStations[i]->removeOwner();
			ownedStations[i]->resetRentTier();
			ownedStations[i]->setOwner(inDebtTo);
			inDebtTo->addStation(ownedStations[i]);
		}
		for(int i = 0; i < ownedUtilities.getSize(); i++) {
			ownedUtilities[i]->removeOwner();
			ownedUtilities[i]->setOwner(inDebtTo);
			inDebtTo->addUtility(ownedUtilities[i]);
		}
		inDebtTo->addMoney(money);
		for(int i = 0; i < releaseCards; i++) {
			inDebtTo->addReleaseCard();
		}
		releaseCards = 0;
	}
	else {
		for (int i = 0; i < ownedProperties.getSize(); i++) {
			ownedProperties[i]->removeOwner();
			ownedProperties[i]->resetRentTier();
		}
		for (int i = 0; i < ownedStations.getSize(); i++) {
			ownedStations[i]->removeOwner();
			ownedStations[i]->resetRentTier();
		}
		for (int i = 0; i < ownedUtilities.getSize(); i++) {
			ownedUtilities[i]->removeOwner();
		}
	}
	ownedProperties.clear();
	ownedStations.clear();
	ownedUtilities.clear();
	money = 0;
	
	//Money transfer
}

size_t Player::getCurrentPosition() const
{
	return position;
}

bool Player::isInGame() const
{
	return inGame;
}

bool Player::isInJail() const
{
	return inJail;
}

bool Player::isInDebt() const
{
	return inDebt;
}

Player* Player::getInDebtTo() const
{
	return inDebtTo;
}

const MyVector<Property*>& Player::getOwnedProperties() const
{
	return ownedProperties;
}

MyVector<Property*>& Player::getOwnedProperties()
{
	return ownedProperties;
}

const MyVector<Station*>& Player::getOwnedStations() const
{
	return ownedStations;
}

MyVector<Station*>& Player::getOwnedStations()
{
	return ownedStations;
}

int Player::getCards() const
{
	return releaseCards;
}

const MyVector<Utility*>& Player::getUtilities() const
{
	return ownedUtilities;
}

MyVector<Utility*>& Player::getUtilities()
{
	return ownedUtilities;
}

int Player::getTimesLeft() const
{
	return timesLeftToRollInJail;
}

void Player::moveTo(size_t newPosition)
{
	int currentPosition = position;
	position = newPosition % GameConstants::BOARD_SIZE;
	if (position < currentPosition) {
		std::cout << "You passed GO! Collect $200!" << std::endl;
		addMoney(GameConstants::PASS_GO_BONUS);
	}
	std::cout << "You are currently on position " << position << std::endl;
	if (inJail) {
		return;
	}
	Monopoly* game = Monopoly::getInstance();
	game->applyFieldEffect(position);
}

void Player::showInfo() const
{
	std::cout << "Player name: " << name << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Money: $" << money << std::endl;
	std::cout << "Position: " << position << std::endl;
	std::cout << "In game: " << (inGame ? "Yes" : "No") << std::endl;
	std::cout << "In jail: " << (inJail ? "Yes" : "No") << std::endl;
	std::cout << "In debt: " << (inDebt ? "Yes" : "No") << std::endl;
	std::cout << "In debt to: " << (inDebtTo ? inDebtTo->getName() : (inDebt ? "Bank" : "None")) << std::endl;
	if (inDebt) {
		std::cout << "Owed money: $" << owedMoney << std::endl;
	}
	std::cout << "Owned properties count: " << ownedProperties.getSize() << std::endl;
	if (ownedProperties.getSize()) {
		for (int i = 0; i < ownedProperties.getSize(); i++) {
			ownedProperties[i]->showProperty();
			std::cout << std::endl;
		}
	}
	std::cout << "Owned stations count: " << ownedStations.getSize() << std::endl;
	if (ownedStations.getSize()) {
		for (int i = 0; i < ownedStations.getSize(); i++) {
			ownedStations[i]->showStation();
			std::cout << std::endl;
		}
	}
	std::cout << "Release cards in hold: " << releaseCards << std::endl;

	std::cout << "Owned Utilities: " << ownedUtilities.getSize() << std::endl;
	if (ownedUtilities.getSize()) {
		for (int i = 0; i < ownedUtilities.getSize(); i++) {
			ownedUtilities[i]->showUtility();
			std::cout << std::endl;
		}
	}
}

void Player::saveToBinary(std::ofstream& ofs) const
{
	ofs.write((const char*)(&id), sizeof(id));
	ofs.write((const char*)(&money), sizeof(money));
	ofs.write((const char*)(&owedMoney), sizeof(owedMoney));

	FileFunctions::saveMyStringToBinaryFile(ofs, name);

	ofs.write((const char*)(&position), sizeof(position));
	ofs.write((const char*)(&inGame), sizeof(inGame));
	ofs.write((const char*)(&inJail), sizeof(inJail));
	ofs.write((const char*)(&inDebt), sizeof(inDebt));

	if (inDebtTo) {
		int inDebtToId = inDebtTo->getId();
		ofs.write((const char*)(&inDebtToId), sizeof(inDebtToId));
	}
	else {
		int inDebtToId = -1;
		ofs.write((const char*)(&inDebtToId), sizeof(inDebtToId));
	}

	ofs.write((const char*)(&timesLeftToRollInJail), sizeof(timesLeftToRollInJail));
	ofs.write((const char*)(&releaseCards), sizeof(releaseCards));
}

void Player::loadFromBinary(std::ifstream& ifs)
{
	int id = 0;
	ifs.read((char*)(&id), sizeof(id));
	this->id = id;
	ifs.read((char*)(&money), sizeof(money));
	ifs.read((char*)(&owedMoney), sizeof(owedMoney));
	name = FileFunctions::loadMyStringFromBinaryFile(ifs);
	ifs.read((char*)(&position), sizeof(position));
	ifs.read((char*)(&inGame), sizeof(inGame));
	ifs.read((char*)(&inJail), sizeof(inJail));
	ifs.read((char*)(&inDebt), sizeof(inDebt));
	int inDebtToId = 0;
	ifs.read((char*)(&inDebtToId), sizeof(inDebtToId));
	if (inDebtToId != -1) {
		inDebtTo = &Monopoly::getInstance()->getPlayer(inDebtToId);
	}
	else {
		inDebtTo = nullptr;
	}
	ifs.read((char*)(&timesLeftToRollInJail), sizeof(timesLeftToRollInJail));
	ifs.read((char*)(&releaseCards), sizeof(releaseCards));
}
