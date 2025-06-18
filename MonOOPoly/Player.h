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
	MyString name;
	size_t position;
	int totalBalance;
	bool inGame = true;
	bool inJail = false;
	bool inDebt = false;
	int timesLeftToRollInJail = GameConstants::TIMES_TO_ROLL_IN_JAIL;
	MyVector<Property*> ownedProperties;
	MyVector<Card*> cards;
	MyVector<Utility*> ownedUtilities;
	MyVector<Station*> ownedStations;
public:
	//Constructors for later
	Player() = default;
	Player(const MyString& name, int money = GameConstants::INITIAL_MONEY);
	Player(int id, const MyString& name, int money, size_t position, int totalBalance, bool isInGame, bool inJail, const MyVector<Property*>& properties, const MyVector<Card*>& cards);

	int getId() const;
	int getMoney() const;
	const MyString& getName() const;
	int getTotalBalance() const;
	size_t getCurrentPosition() const;
	bool isInGame() const;
	bool isInJail() const;
	bool isInDebt() const;
	const MyVector<Property*>& getOwnedProperties() const;
	MyVector<Property*>& getOwnedProperties();
	const MyVector<Station*>& getOwnedStations() const;
	MyVector<Station*>& getOwnedStations();
	const MyVector<Card*>& getCards() const;
	MyVector<Card*>& getCards();
	const MyVector<Utility*>& getUtilities() const;
	MyVector<Utility*>& getUtilities();
	int getTimesLeft() const;

	void removeProperty(Property* property);
	void decreaseTimesLeft();
	void setJailStatus();
	void setInDebtStatus();
	void addProperty(Property* property);
	void addStation(Station* station);
	void addCard(Card* card);
	void addUtility(Utility* utility);
	void addMoney(int amount);
	void resign();
	void moveTo(size_t newPosition);
	void showInfo() const;
};

