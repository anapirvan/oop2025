#pragma once
#include "Car.h"
#include "Weather.h"

class Fiat :public Car
{
public:
	Fiat();
	int getRaceTimeInHours(int circuitLength, Weather conditions);
	const char* getName();
	int getfuelCapacity();
	int getfuelConsumption();
};