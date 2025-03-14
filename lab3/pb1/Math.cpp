#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <iostream>
using namespace std;
int Math::Add(int n1, int n2)
{
	return n1 + n2;
}

int Math::Add(int n1, int n2, int n3)
{
	return n1 + n2 + n3;
}

int Math::Add(double n1, double n2)
{
	return n1 + n2;
}

int Math::Add(double n1, double n2, double n3)
{
	return n1 + n2 + n3;
}

int Math::Mul(int n1, int n2)
{
	return n1 * n2;
}

int Math::Mul(int n1, int n2, int n3)
{
	return n1 * n2 * n3;
}

int Math::Mul(double n1, double n2)
{
	return n1 * n2;
}

int Math::Mul(double n1, double n2, double n3)
{
	return n1 * n2 * n3;
}

int Math::Add(int count, ...)
{
	int suma=0;
	va_list args;
	va_start(args, count);
	for (int i = 0;i < count;i++)
		suma += va_arg(args, int);
	va_end(args);
	return suma;
}

char* Math::Add(const char* n1, const char* n2)
{
	char* suma;
	if (n1 == nullptr || n2 == nullptr)
		return nullptr;
	
	int l1, l2,i,j,aux,k;
	l1 = strlen(n1);
	l2 = strlen(n2);
	i = l1 - 1;
	j = l2 - 1;
	k = max(l1, l2) + 1;
	suma = new char[k];
	suma[k] = 0;
	k -= 1;
	for (int i = 0;i <= k;i++)
		suma[i] = '0';
	//suma[--k] = 0;
	while(i>=0 and j>=0)
		{
			aux=(suma[k]-'0')+ (n1[i] - '0') + (n2[j] - '0');
			suma[k] = aux%10 + '0';
			aux = (suma[k - 1] - '0') + aux / 10;
			suma[k - 1] = aux+'0';
			i--; j--;k--;
		}
	while (i >= 0)
	{
		aux = (suma[k] - '0') + (n1[i] - '0');
		suma[k] = aux%10 + '0';
		aux = (suma[k - 1] - '0') + aux / 10;
		suma[k - 1] = aux + '0';
		i--; k--;
	}
	while (j >= 0)
	{
		aux = (suma[k] - '0') + (n2[j] - '0');
		suma[k] = aux%10 + '0';
		aux = (suma[k - 1] - '0') + aux / 10;
		suma[k - 1] = aux + '0';
		j--; k--;
	}
	if (suma[0] == '0')
	{
		for (i = 0;i < strlen(suma);i++)
			suma[i] = suma[i + 1];
	}
	return suma;
}