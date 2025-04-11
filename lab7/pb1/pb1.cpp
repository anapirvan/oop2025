
#include <iostream>

float operator"" _Kelvin(const char* sir)
{
    int nr = 0, i;
    for (i = 0;sir[i];i++)
        nr = nr * 10 + sir[i] - '0';
    return nr + 273, 15;
}

float operator"" _Farenheit(const char* sir)
{
    int nr = 0, i;
    for (i = 0;sir[i];i++)
        nr = nr * 10 + sir[i] - '0';
    return nr * 1.8 + 32;
}
int main()
{
    float a = 300_Kelvin;
    float b = 120_Farenheit;
    std::cout << a << " " << b;
    return 0;
}

