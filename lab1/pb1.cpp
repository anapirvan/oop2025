

#include <iostream>
int conversieSir(char str[])
{
    int number = 0;
    for (int i = 0;str[i]>='0' and str[i]<='9';i++)
        number = number * 10 + (str[i] - '0');
    return number;
}
int suma_numere(const char* filePath)
{
    FILE* fileHandle;
    char str[10];
    int number, suma = 0;
    fileHandle = fopen(filePath, "r");
    while (fgets(str, 10, fileHandle) != NULL)
    {
        number = conversieSir(str);
        suma += number;
    }
    return suma;
}
int main()
{
    int suma;
    suma = suma_numere("in.txt");
    printf("%d",suma);

}


