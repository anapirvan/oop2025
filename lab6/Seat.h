#pragma once
#include "Car.h"
#include "Weather.h"

class Seat :public Car
{
public:
	Seat();
	int getRaceTimeInHours(int circuitLength, Weather conditions);
	const char* getName();
	int getfuelCapacity();
	int getfuelConsumption();
};

