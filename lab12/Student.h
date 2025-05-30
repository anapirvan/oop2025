#pragma once
#include<string>
#include "Materie.h"
#include<vector>
#include<map>
#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

enum limba
{
	ro, en
};


struct comparator
{
	bool operator()(const Materie& m1, const Materie& m2) const
	{
		return (m1.GetNume() < m2.GetNume());
	}
};


class Student
{
private:
	string nume;
	string nr_materii;
	limba lb;
	set<Materie, comparator> materii;
	map<string, int> note;

public:
	Student(string num, string nrM, limba l)
	{
		nume = num;
		nr_materii = nrM;
		lb = l;
	}
	void InserareMaterie(Materie m, int nota)
	{
		materii.insert(m);
		note[m.GetNume()] = nota;
	}
	void afisareNote()
	{
		for (auto it = note.begin(); it != note.end(); it++)
		{
			cout << it->first << " " << it->second << '\n';
		}
	}
	
	string GetNum()
	{
		return nume;
	}

	float Medie()
	{
		float media = 0;
		for (auto it = note.begin(); it != note.end();it++)
		{
			media += it->second;
		}
		media = media / materii.size();
		return media;
	}
};