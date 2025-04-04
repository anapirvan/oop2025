#include "BMW.h"
#include "Weather.h"

BMW::BMW()
{
	fuelCapacity = 45;
	fuelConsumption = 20;
	avarageSpeed[Weather::Rain] = 100;
	avarageSpeed[Weather::Sunny] = 90;
	avarageSpeed[Weather::Snow] = 80;
}

int BMW::getRaceTimeInHours(int circuitLength, Weather conditions)
{
	return circuitLength / avarageSpeed[conditions] + 2;
}

const char* BMW::getName()
{
	return "BMW";
}

int BMW::getfuelCapacity()
{
	return fuelCapacity;
}

int BMW::getfuelConsumption()
{
	return fuelConsumption;
}