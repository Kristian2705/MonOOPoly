#include "MovePositionCard.h"

MovePositionCard::MovePositionCard(const MyString& description, MoveTypes moveType)
	: Card(description), moveType(moveType)
{ }

void MovePositionCard::applyEffect() const
{
	switch (moveType)
	{
		case MoveTypes::GoToStart:
			break;
		case MoveTypes::GoToJail:
			break;
		case MoveTypes::GoToIllinois:
			break;
		case MoveTypes::GoToStCharles:
			break;
		case MoveTypes::GoToNearestRailroad:
			break;
		case MoveTypes::GoToNearestUtility:
			break;
		case MoveTypes::GetOutOfJailFree:
			break;
		case MoveTypes::GoBackThreeSpaces:
			break;
		case MoveTypes::GoToReadingRailroad:
			break;
		case MoveTypes::GoToBroadwalk:
			break;
		default:
			break;
	}
}

Card* MovePositionCard::clone() const
{
	return new MovePositionCard(*this);
}
