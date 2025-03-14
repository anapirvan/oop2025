
#include <iostream>
#include"Math.h"
using namespace std;
int main()
{
    cout << Math::Add(63, 965) << endl;

    cout << Math::Add(63, 965, 4267) << endl;

    cout << Math::Add(63.7, 965.9) << endl;

    cout << Math::Add(63.7, 965.9, 4267.5) << endl;

    cout << Math::Mul(12, 8) << endl;

    cout << Math::Mul(12, 8, 5) << endl;

    cout << Math::Mul(12.5, 8.3) << endl;

    cout << Math::Mul(12.5, 8.3, 5.7) << endl;

    cout << Math::Add(4, 2, 3, 5, 7) << endl;

    cout<<Math::Add("8879","3219");
}

