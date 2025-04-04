#pragma once
#include "Car.h"
#include "Weather.h"

class BMW :public Car
{
public:
	BMW();
	int getRaceTimeInHours(int circuitLength, Weather conditions);
	const char* getName();
	int getfuelCapacity();
	int getfuelConsumption();
};