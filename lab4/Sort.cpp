#include "Sort.h"
#include < stdio.h > 
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdarg>
#include <cstring>
using namespace std;

Sort::Sort(int nr_elem, int min, int max)
{
	this->nr_elem = nr_elem;
	v = new int[nr_elem];
	srand(time(NULL));
	for (int i = 0;i < nr_elem;i++)
		v[i] = min + rand() % (max - min + 1);
}

Sort::Sort(int *vector, int nr_elem)
{
	this->nr_elem = nr_elem;
	v = new int[nr_elem];
	for (int i = 0;i < nr_elem;i++)
		v[i] = vector[i];
}

Sort::Sort(int count, ...)
{
	this->nr_elem = count;
	v = new int[count];
	va_list args;
	va_start(args, count);
	for (int i = 0;i < count;i++)
		v[i] = va_arg(args, int);
	va_end(args);

}

Sort::Sort(char* string)
{
	char* copie;
	copie = new char[strlen(string)+1];
	for (int i = 0;string[i];i++)
		copie[i] = string[i];
	char* t;
	t = strtok(copie, ",");
	int nr_elem = 0;
	while (t)
	{
		nr_elem++;
		t = strtok(NULL, ",");
	}
	this->nr_elem = nr_elem;
	v = new int[nr_elem];
	t = strtok(string, ",");
	int k = 0;
	while (t)
	{
		int nr = 0;
		for (int i = 0;t[i];i++)
			nr = nr * 10 + t[i] - '0';
		v[k++] = nr;
		t = strtok(NULL, ",");
	}
}

void Sort::InsertSort(bool ascendent )
{
	if (ascendent)
	{
		for (int i = 0;i < nr_elem ;i++)
		{
			int x = v[i];
			int j = i - 1;
			while (j >= 0 and x < v[j])
			{
				v[j+1] = v[j];
				j--;
			}
			v[j+1] = x;
		}
	}
	else
	{
		for (int i = 0;i < nr_elem;i++)
		{
			int x = v[i];
			int j = i - 1;
			while (j >= 0 and x > v[j])
			{
				v[j + 1] = v[j];
				j--;
			}
			v[j + 1] = x;
		}
	}
}

void Sort::BubbleSort(bool ascendent)
{
	bool sorted;
	if (ascendent)
	{
		do
		{
			sorted = 1;
			for (int i = 0;i < nr_elem-1;i++)
				if (v[i] > v[i + 1])
				{
					swap(v[i], v[i + 1]);
					sorted = 0;
				}
		} while (!sorted);
	}
	else
		do
		{
		    sorted = 1;
			for (int i = 0;i < nr_elem-1;i++)
				if (v[i] < v[i + 1])
				{
					swap(v[i], v[i + 1]);
					sorted = 0;
				}
		} while (!sorted);
}

int Sort::Partitie( int st, int dr,bool ascendent)
{
	if (ascendent)
	{
		int p = v[dr];
		int i = st - 1;
		for (int j = st;j <= dr;j++)
			if (v[j] < p)
			{
				i++;
				swap(v[i], v[j]);
			}
		swap(v[i + 1], v[dr]);
		return i + 1;
	}
	else
	{
		int p = v[dr];
		int i = st - 1;
		for (int j = st;j <= dr;j++)
			if (v[j] > p)
			{
				i++;
				swap(v[i], v[j]);
			}
		swap(v[i + 1], v[dr]);
		return i + 1;
	}
}

void Sort::QuickSortRecursiv(int st,int dr,bool ascendent)
{
	if (st < dr)
	{
		int p = Partitie(st, dr, ascendent);
		QuickSortRecursiv(st, p - 1, ascendent);
		QuickSortRecursiv(p + 1, dr, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortRecursiv(0, nr_elem - 1, ascendent);
}

int Sort::GetElementsCount()
{
	return nr_elem;
}

int Sort::GetElementFromIndex(int index)
{
	return v[index];
}

void Sort::Print()
{
	for (int i = 0;i < nr_elem;i++)
		cout << v[i] << " ";
}
