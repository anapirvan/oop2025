#pragma once
#include"Student.h"
#include<vector>
#include<functional>
#include <algorithm>
using namespace std;

bool compare(const pair<string, float>& n1, const pair<string, float>& n2)
{
	if (n1.second > n2.second)
		return true;
	if (n1.second == n2.second && n1.first < n2.first)
		return true;
	return false;
}

class Catalog
{
protected:
	vector<Student> student;
public:
	void InserareStudent(Student& s)
	{
		student.push_back(s);
	}
	void virtual GetGrades(string nume) = 0;
	void virtual MedieNote(string nume) = 0;
	vector<Student> Filtrare(function<bool(Student&)> f)
	{
		vector<Student> aux;
		for (auto it = student.begin(); it != student.end(); it++)
		{
			if (f(*it))
				aux.push_back(*it);
		}
		return aux;
	}

	vector<pair<string, float>> Clasificare()
	{
		vector<pair<string, float>> rank;
		for (auto& i : student)
		{
			rank.push_back(pair<string, float>(i.GetNum(), i.Medie()));
		}
		sort(rank.begin(), rank.end(), compare);
		return rank;
	}
};

class CatalogRo :public Catalog
{
public:
	void GetGrades(string nume)
	{
		for (auto& it : student)
		{
			if (nume == it.GetNum())
			{
				it.afisareNote();
			}
		}
	}

	void MedieNote(string nume)
	{
		for (auto it = student.begin(); it != student.end(); it++)
		{
			if (nume == it->GetNum())
			{
				cout << it->Medie() << '\n';
			}
		}
	}
};

class CatalogEn :public Catalog
{
public:
	void GetGrades(string nume)
	{
		for (auto it = student.begin();it != student.end(); it++)
		{
			if (nume == it->GetNum())
			{
				it->afisareNote();
			}
		}
	}

	/*void MedieNote(string nume)
	{
		for (auto it = student.begin(); it != student.end(); it++)
		{
			if (nume == it->GetNum())
			{
				cout << "the average grade of student " << nume << " is:" << it->Medie() << '\n';
			}
		}
	}*/
};