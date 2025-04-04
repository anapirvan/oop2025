#pragma once
#include "Car.h"
#include "Weather.h"

class Volvo :public Car
{
public:
	Volvo();
	int getRaceTimeInHours(int circuitLength, Weather conditions);
	const char* getName();
	int getfuelCapacity();
	int getfuelConsumption();
};