#pragma once
#include<string>
using namespace std;

enum tip
{
	obligatoriu, facultativ, optional
};

class Materie
{
protected:
	tip Tip;
	string nume;
	int nr_credite;
public:
	string GetNume() const
	{
		return nume;
	}
};

class Romana :public Materie
{
public:
	Romana()
	{
		Tip = obligatoriu;
		nume = "romana";
		nr_credite = 4;
	}
};

class Engleza :public Materie
{
public:
	Engleza()
	{
		Tip = obligatoriu;
		nume = "engleza";
		nr_credite = 2;
	}
};

class Spaniola :public Materie
{
public:
	Spaniola()
	{
		Tip = facultativ;
		nume = "spaniola";
		nr_credite = 1;
	}
};


class Informatica :public Materie
{
public:
	Informatica()
	{
		Tip = obligatoriu;
		nume = "informatica";
		nr_credite = 5;
	}
};

class Optional1 :public Materie
{
public:
	Optional1()
	{
		Tip = optional;
		nume = "optional1";
		nr_credite = 1;
	}
};

class Optional2 :public Materie
{
public:
	Optional2()
	{
		Tip = optional;
		nume = "optional2";
		nr_credite = 1;
	}
};


