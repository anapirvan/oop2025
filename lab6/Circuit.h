#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{
	Weather circuitConditions;
	unsigned int nrCars;
	unsigned int length;
	Car* cars[100];
	unsigned int DidFinish[100];
	const char* DidNotFinish[100];
	int k1, k2;

public:
	Circuit();
	void AddCar(Car* otherCar);
	//new Volvo() -> *Volvo
	void SetLength(int length);
	void SetWeather(Weather circuitConditions);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};