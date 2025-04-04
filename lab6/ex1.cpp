
#include <iostream>
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Circuit.h"
#include "Fiat.h"
#include "RangeRover.h"

int main()
{
    Circuit c;

    //alocare statica
    Volvo v1;

    //alocare dinamica
    Volvo* v2;
    v2 = new Volvo();

    c.SetLength(100);
    c.SetWeather(Weather::Rain);

    c.AddCar(new Volvo());//cars[0]=pointer catre un obiect Volvo
    c.AddCar(new BMW());//cars[1]=pointer catre un obiect BMW
    c.AddCar(new Seat());
    c.AddCar(new Fiat());
    c.AddCar(new RangeRover());

    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();
}

