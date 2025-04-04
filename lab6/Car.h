#pragma once
#include "Weather.h"

class Car
{
protected:
	int fuelCapacity;
	int fuelConsumption;
	int avarageSpeed[3];//0 - viteza ploaie, 1 - viteza soare, 2 - viteza zapada
public:
	virtual int getRaceTimeInHours(int circuitLenghth, Weather conditions) = 0;
	virtual const char* getName() = 0;
	virtual int getfuelCapacity() = 0;
	virtual int getfuelConsumption() = 0;

	
};