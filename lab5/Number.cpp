#include "Number.h"
#include<cstring>
#include <iostream>
#include<algorithm>
using namespace std;

Number::Number(const char* value, int base)
{
	this->numar = new char[100];
	strcpy(numar, value);
	this->baza = base;
}

void Number::Print()
{
	std::cout << numar << " " << baza << endl;
}

Number::~Number()
{
	delete[]numar;
	numar = nullptr;
}

Number Number::operator + (Number& nr)
{
	int baza_max;
	if(this->baza!=nr.baza)
		if (this->baza > nr.baza)
		{
			baza_max = baza;
		}
		else
		{
			baza_max = nr.baza;
		}
	int a1 = 0, a2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			a1 = a1 * baza + numar[i] - '0';
		else
			a1 = a1 * baza + numar[i] - 'A' + 10;

	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			a2 = a2 * nr.baza + nr.numar[i] - '0';
		else
			a2 = a2 * nr.baza + nr.numar[i] - 'A' + 10;
	a1 += a2;
	char* sir = new char[100];
	int k = 0;
	while (a1 > 0)
	{
		sir[k++] = a1 % 10 + '0';
		a1 /= 10;
	}
	sir[k] = 0;
	reverse(sir, sir + k);
	Number rez(sir, 10);
	rez.SwitchBase(baza_max);
	delete[]sir;
	return rez;
		
}

Number Number::operator - (Number& nr)
{
	int baza_max;
	if (this->baza != nr.baza)
		if (this->baza > nr.baza)
		{
			baza_max = baza;
		}
		else
		{
			baza_max = nr.baza;
		}
	int a1 = 0, a2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			a1 = a1 * baza + numar[i] - '0';
		else
			a1 = a1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			a2 = a2 * nr.baza + nr.numar[i] - '0';
		else
			a2 = a2 * nr.baza + nr.numar[i] - 'A' + 10;
	a1 -= a2;
	char* sir = new char[100];
	int k = 0;
	while (a1 > 0)
	{
		sir[k++] = a1 % 10 + '0';
		a1 /= 10;
	}
	sir[k] = 0;
	reverse(sir, sir + k);
	Number rez(sir, 10);
	rez.SwitchBase(baza_max);
	delete[]sir;
	return rez;

}

Number& Number::operator =(const Number& nr)
{
	strcpy(numar, nr.numar);
	baza = nr.baza;
	return (*this);
}

Number& Number::operator +=(Number& nr)
{

	int a1 = 0, a2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			a1 = a1 * baza + numar[i] - '0';
		else
			a1 = a1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			a2 = a2 * nr.baza + nr.numar[i] - '0';
		else
			a2 = a2 * nr.baza + nr.numar[i] - 'A' + 10;
	a1 += a2;
	char* sir = new char[100];
	int k = 0;
	while (a1 > 0)
	{
		sir[k++] = a1 % 10 + '0';
		a1 /= 10;
	}
	sir[k] = 0;
	reverse(sir, sir + k);
	int baza_fin = this->baza;
	strcpy(this->numar, sir);
	this->baza = 10;
	(*this).SwitchBase(baza_fin);
	delete[]sir;
	return (*this);
}

Number& Number::operator -=(Number& nr)
{

	int a1 = 0, a2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			a1 = a1 * baza + numar[i] - '0';
		else
			a1 = a1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			a2 = a2 * nr.baza + nr.numar[i] - '0';
		else
			a2 = a2 * nr.baza + nr.numar[i] - 'A' + 10;
	a1 -= a2;
	char* sir = new char[100];
	int k = 0;
	while (a1 > 0)
	{
		sir[k++] = a1 % 10 + '0';
		a1 /= 10;
	}
	sir[k] = 0;
	reverse(sir, sir + k);
	int baza_fin = this->baza;
	strcpy(this->numar, sir);
	this->baza = 10;
	(*this).SwitchBase(baza_fin);
	delete[]sir;
	return (*this);
}

bool Number::operator < (const Number& nr)
{
	int v1 = 0, v2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			v1 = v1 * baza + numar[i] - '0';
		else
			v1 = v1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			v2 = v2 * nr.baza + nr.numar[i] - '0';
		else
			v2 = v2 * nr.baza + nr.numar[i] - 'A' + 10;
	if (v1 < v2)
		return true;
	return false;
}

bool Number::operator > (const Number& nr)
{
	int v1 = 0, v2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			v1 = v1 * baza + numar[i] - '0';
		else
			v1 = v1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			v2 = v2 * nr.baza + nr.numar[i] - '0';
		else
			v2 = v2 * nr.baza + nr.numar[i] - 'A' + 10;
	if (v1 > v2)
		return true;
	return false;
}

bool Number::operator <= (const Number& nr)
{
	int v1 = 0, v2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			v1 = v1 * baza + numar[i] - '0';
		else
			v1 = v1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			v2 = v2 * nr.baza + nr.numar[i] - '0';
		else
			v2 = v2 * nr.baza + nr.numar[i] - 'A' + 10;
	if (v1 <= v2)
		return true;
	return false;
}

bool Number::operator >= (const Number& nr)
{
	int v1 = 0, v2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			v1 = v1 * baza + numar[i] - '0';
		else
			v1 = v1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			v2 = v2 * nr.baza + nr.numar[i] - '0';
		else
			v2 = v2 * nr.baza + nr.numar[i] - 'A' + 10;
	if (v1 >= v2)
		return true;
	return false;
}

bool Number::operator == (const Number& nr)
{
	int v1 = 0, v2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			v1 = v1 * baza + numar[i] - '0';
		else
			v1 = v1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			v2 = v2 * nr.baza + nr.numar[i] - '0';
		else
			v2 = v2 * nr.baza + nr.numar[i] - 'A' + 10;
	if (v1 == v2)
		return true;
	return false;
}

bool Number::operator != (const Number& nr)
{
	int v1 = 0, v2 = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			v1 = v1 * baza + numar[i] - '0';
		else
			v1 = v1 * baza + numar[i] - 'A' + 10;
	for (int i = 0;nr.numar[i];i++)
		if (nr.numar[i] >= '0' and nr.numar[i] <= '9')
			v2 = v2 * nr.baza + nr.numar[i] - '0';
		else
			v2 = v2 * nr.baza + nr.numar[i] - 'A' + 10;
	if (v1 != v2)
		return true;
	return false;
}

char Number::operator [](int index)
{
	return numar[index];
}

Number& Number::operator =(int nr)
{
	char* sir = new char[10];
	int k = 0;
	while (nr > 0)
	{
		sir[k++] = nr % 10 + '0';
		nr /= 10;
	}
	sir[k] = 0;
	reverse(sir, sir + k);
	strcpy(numar, sir);
	int baza_finala = baza;
	baza = 10;
	this->SwitchBase(baza_finala);
	delete[]sir;
	return (*this);
}

Number& Number::operator =(const char* sir)
{
	int baza_fin = baza;
	baza = 10;
	strcpy(numar, sir);
	this->SwitchBase(baza_fin);
	return (*this);
}

Number& Number::operator =(Number&& nr)
{
	numar = nr.numar;
	nr.numar = nullptr;
	baza = nr.baza;
	return (*this);
}

Number& Number::operator --()
{
	strcpy(numar, numar + 1);
	return (*this);
}

Number& Number::operator --(int)
{
	int l = strlen(numar);
	numar[l - 1] = 0;
	return (*this);
}

int Number::GetBase()
{
	return this->baza;
}

void Number::SwitchBase(int newBase)
{
	int v = 0, k = 0;
	for (int i = 0;numar[i];i++)
		if (numar[i] >= '0' and numar[i] <= '9')
			v = v * baza + numar[i] - '0';
		else
			v = v * baza + numar[i] - 'A' + 10;
	char* a = new char[100];
	while (v > 0)
	{
		int r = (v % newBase);
		if (r < 10)
			a[k++] = r + '0';
		else
			a[k++] = r - 10 + 'A';
		v /= newBase;
	}
	a[k] = 0;
	reverse(a, a + k);
	this->baza = newBase;
	strcpy(numar, a);
	delete[]a;
}

int Number::GetDigitsCount()
{
	return strlen(numar);
}

Number::Number(int nr)
{
	char* sir = new char[10];
	int k = 0;
	while (nr>0)
	{
		sir[k++] = nr % 10 + '0';
		nr /= 10;
	}
	sir[k] = 0;
	reverse(sir, sir + k);
	numar = new char[100];
	strcpy(numar, sir);
	baza = 10;
	delete[]sir;
}