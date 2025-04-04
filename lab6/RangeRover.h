#pragma once
#include "Car.h"
#include "Weather.h"

class RangeRover :public Car
{
public:
	RangeRover();
	int getRaceTimeInHours(int circuitLength, Weather conditions);
	const char* getName();
	int getfuelCapacity();
	int getfuelConsumption();
};
