#pragma once
#include "Property.h"
#include "MyVector.hpp"
#include "Station.h"
#include "Utility.h"
#include <memory>
class Card;

class Player
{
	static int nextId;
	int id;
	int money;
	int owedMoney;
	MyString name;
	size_t position;
	int totalBalance;
	bool inGame = true;
	bool inJail = false;
	bool inDebt = false;
	int timesLeftToRollInJail = GameConstants::TIMES_TO_ROLL_IN_JAIL;
	int releaseCards = GameConstants::RELEASE_CARDS_INITIAL_VALUE;
	Player* inDebtTo = nullptr;
	MyVector<Property*> ownedProperties;
	MyVector<Utility*> ownedUtilities;
	MyVector<Station*> ownedStations;
public:
	//Constructors for later
	Player() = default;
	Player(const MyString& name, int money = 100);
	Player(int id, const MyString& name, int money, size_t position, int totalBalance, bool isInGame, bool inJail, const MyVector<Property*>& properties, const MyVector<Card*>& cards);

	int getId() const;
	int getMoney() const;
	int getOwedMoney() const;
	const MyString& getName() const;
	int getTotalBalance() const;
	size_t getCurrentPosition() const;
	bool isInGame() const;
	bool isInJail() const;
	bool isInDebt() const;
	Player* getInDebtTo() const;
	const MyVector<Property*>& getOwnedProperties() const;
	MyVector<Property*>& getOwnedProperties();
	const MyVector<Station*>& getOwnedStations() const;
	MyVector<Station*>& getOwnedStations();
	int getCards() const;
	const MyVector<Utility*>& getUtilities() const;
	MyVector<Utility*>& getUtilities();
	int getTimesLeft() const;

	void removeProperty(Property* property);
	void removeStation(Station* station);
	void removeUtility(Utility* utility);
	void decreaseTimesLeft();
	void setJailStatus();
	void setInDebtStatus();
	void setInDebtTo(Player* player);
	void setOwedMoney(int amount);
	void addProperty(Property* property);
	void addStation(Station* station);
	void addReleaseCard();
	void removeReleaseCard();
	void addUtility(Utility* utility);
	void addMoney(int amount);
	void resign();
	void moveTo(size_t newPosition);
	void showInfo() const;
};

