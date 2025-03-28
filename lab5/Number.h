#pragma once
#include<cstring>

class Number
{
	char* numar;
	unsigned int baza;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& nr) { numar = new char[100]; strcpy(numar, nr.numar); baza = nr.baza; }
	Number(Number&& nr) { numar = nr.numar; baza = nr.baza; }
	Number(int nr);
	// add operators and copy/move constructor

	Number operator +(Number& nr);
	Number operator -(Number& nr);
	Number& operator =(const Number& nr);
	Number& operator +=( Number& nr);
	Number& operator -=(Number& nr);
	bool operator <(const Number& nr); 
	bool operator >(const Number& nr);
	bool operator <=(const Number& nr);
	bool operator >=(const Number& nr);
	bool operator ==(const Number& nr);
	bool operator !=(const Number& nr);
	char operator [](int index);
	Number& operator =(int nr);
	Number& operator =(const char *sir);
	Number& operator =(Number&& nr);
	Number& operator --();
	Number& operator --(int);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
