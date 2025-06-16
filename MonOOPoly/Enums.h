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

enum class ColorSetBuildings {
	Brown = 2,
	LightBlue,
	Pink = 3,
	Orange = 3,
	Red = 3,
	Yellow = 3,
	Green = 3,
	Blue = 2
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