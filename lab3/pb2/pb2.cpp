
#include "Canvas.h"
#include <iostream>
using namespace std;
int main()
{
    Canvas canvas(10, 10);
    canvas.DrawCircle(4, 4, 3, '*');
    canvas.Print();

    cout << endl;
    
    canvas.Clear();
    canvas.FillCircle(4, 4, 3, '*');
    canvas.Print();

    cout << endl;

    canvas.Clear();
    canvas.DrawRect(2, 1, 8, 4, '*');
    canvas.Print();

    cout << endl;

    canvas.Clear();
    canvas.FillRect(2, 1, 8, 4, '*');
    canvas.Print();

    cout << endl;

    canvas.Clear();
    canvas.SetPoint(4, 7, '*');
    canvas.Print();

    cout << endl;

    canvas.Clear();
    canvas.DrawLine(1, 3, 7, 9, '*');
    canvas.Print();
}

