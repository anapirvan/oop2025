#include "Circuit.h"
#include "Car.h"
#include<iostream>
using namespace std;

Circuit::Circuit()
{
	nrCars = 0;
	circuitConditions = Weather::Sunny;
	
}

void Circuit::AddCar(Car* otherCar)
{
	cars[nrCars] = otherCar;
	nrCars++;
}

void Circuit::SetLength(int length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather circuitConditions)
{
	this->circuitConditions = circuitConditions;
}

void Circuit::Race()
{
	k1 = 0; k2 = 0;
	for (int i = 0;i < nrCars;i++)
	{
		int x = (this->length) * (cars[i]->getfuelConsumption());
		x /= 100;
		if (x <= cars[i]->getfuelCapacity())
			DidFinish[k1++] = cars[i]->getRaceTimeInHours(length, circuitConditions);
		else
			DidNotFinish[k2++] = cars[i]->getName();

	}
	
}

void Circuit::ShowFinalRanks()
{
	unsigned int c[100];
	for (int i = 0;i < nrCars;i++)
		c[i] = cars[i]->getRaceTimeInHours(length,circuitConditions);

	bool sorted;
	do
	{
		sorted = 1;
		for (int i = 0;i < k1-1 ;i++)
			if (DidFinish[i] > DidFinish[i + 1])
			{
				swap(DidFinish[i], DidFinish[i + 1]);
				sorted = 0;
			}
	} while (!sorted);

	cout << "Clasamentul este:" << endl;
	for (int i = 0;i < k1;i++)
	{
		int j;
		for (j = 0;j < nrCars;j++)
			if (DidFinish[i] == c[j])
				break;
		cout << cars[j]->getName() <<" "<< DidFinish[i] << endl;

	}
	cout << endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	cout << "Masinile care nu au terminat sunt: ";
	for (int i = 0;i < k2;i++)
		cout << DidNotFinish[i] << " ";
	cout << endl;
}