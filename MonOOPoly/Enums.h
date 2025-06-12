#pragma once

enum class ColorSet
{
	Brown,
	LightBlue,
	Pink,
	Orange,
	Red,
	Yellow,
	Green,
	Blue,
};

enum class MoveTypes
{
	GoToStart,
	GoToJail,
	GoToIllinois,
	GoToStCharles,
	GoToNearestRailroad,
	GoToNearestUtility,
	GetOutOfJailFree,
	GoBackThreeSpaces,
	GoToReadingRailroad,
	GoToBroadwalk
};

enum class SignlePaymentTypes {
	BankPaysYouDivident,
	GeneralRepairs,
	PayPoorTax,
	BankError,
	DoctorFee,
	SaleOfStock,
	HolidayFunds,
	IncomeTaxRefund,
	LifeInsurance,

};