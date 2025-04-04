#include "RangeRover.h"
#include "Weather.h"

RangeRover::RangeRover()
{
	fuelCapacity = 35;
	fuelConsumption = 15;
	avarageSpeed[Weather::Rain] = 70;
	avarageSpeed[Weather::Sunny] = 110;
	avarageSpeed[Weather::Snow] = 80;
}

int RangeRover::getRaceTimeInHours(int circuitLength, Weather conditions)
{
	return circuitLength / avarageSpeed[conditions] +1;
}

const char* RangeRover::getName()
{
	return "RangeRover";
}

int RangeRover::getfuelCapacity()
{
	return fuelCapacity;
}

int RangeRover::getfuelConsumption()
{
	return fuelConsumption;
}