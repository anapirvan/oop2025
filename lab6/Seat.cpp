#include "Seat.h"
#include "Weather.h"

Seat::Seat()
{
	fuelCapacity = 10;
	fuelConsumption = 5;
	avarageSpeed[Weather::Rain] = 50;
	avarageSpeed[Weather::Sunny] = 95;
	avarageSpeed[Weather::Snow] = 60;
}

int Seat::getRaceTimeInHours(int circuitLength, Weather conditions)
{
	return circuitLength / avarageSpeed[conditions]+2;
}

const char* Seat::getName()
{
	return "Seat";
}

int Seat::getfuelCapacity()
{
	return fuelCapacity;
}

int Seat::getfuelConsumption()
{
	return fuelConsumption;
}