#include "Fiat.h"
#include "Weather.h"

Fiat::Fiat()
{
	fuelCapacity = 4;
	fuelConsumption = 5;
	avarageSpeed[Weather::Rain] = 50;
	avarageSpeed[Weather::Sunny] = 95;
	avarageSpeed[Weather::Snow] = 60;
}

int Fiat::getRaceTimeInHours(int circuitLength, Weather conditions)
{
	return circuitLength / avarageSpeed[conditions]+8;
}

const char* Fiat::getName()
{
	return "Fiat";
}

int Fiat::getfuelCapacity()
{
	return fuelCapacity;
}

int Fiat::getfuelConsumption()
{
	return fuelConsumption;
}