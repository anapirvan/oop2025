#include "Volvo.h"
#include "Weather.h"

Volvo::Volvo()
{
	fuelCapacity = 40;
	fuelConsumption = 8;
	avarageSpeed[Weather::Rain] = 80;
	avarageSpeed[Weather::Sunny] = 130;
	avarageSpeed[Weather::Snow] = 150;
}

int Volvo::getRaceTimeInHours(int circuitLength, Weather conditions)
{
	return circuitLength / avarageSpeed[conditions] +7;
}

const char* Volvo::getName()
{
	return "Volvo";
}

int Volvo::getfuelCapacity()
{
	return fuelCapacity;
}

int Volvo::getfuelConsumption()
{
	return fuelConsumption;
}