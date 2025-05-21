//#include "pch.h"
//#include <iostream>
//using namespace std;
//
//template<class T>
//int comp(T& elem1, T& elem2)
//{
//	if (elem1 < elem2)
//		return -1;
//	else
//		if (elem1 == elem2)
//			return 0;
//	return 1;
//}
//
//template<class T>
//void sortare(T* v, int n, int (*compare)(const T&, const T&))
//{
//	bool sortat;
//	do {
//		sortat = 1;
//		for (int i = 0;i < n;i++)
//			if (compare(v[i],v[i + 1])<0)
//			{
//				swap(v[i], v[i + 1]);
//				sortat = 0;
//			}
//	} while (!sortat);
//	
//}
//
//TEST(Sortare, SortareDesc) { 
//	int v[] = { 4,7,1,0,2,3 };
//	sortare(&v[0], 6, comp);
//	for (int i = 0;i < 5;i++)
//		for (int j = i + 1;j < 6;j++)
//			EXPECT_GE(v[i], v[j]);
//	for (int i = 0;i < sizeof(v) / sizeof(v[0]);i++)
//		cout << v[i] << " ";
//}

#include "pch.h"
#include <iostream>
using namespace std;

template<class T>
int comp(const T& elem1,const T& elem2)
{
	if (elem1 < elem2)
		return 1;
	else
		if (elem1 == elem2)
			return 0;
	return 1;
}

template<class T>
void sortare(T* v, int n, int (*compare)(const T&, const T&))
{
	bool sortat;
	do {
		sortat = 1;
		for (int i = 0;i < n-1;i++)
			if (compare(v[i],v[i + 1])>0)
			{
				swap(v[i], v[i + 1]);
				sortat = 0;
			}
	} while (sortat);
	
}

TEST(Sortare, SortareDesc) { 
	int v[] = { 4,7,1,0,2,3 };
	sortare(&v[0], 6, comp);
	for (int i = 0;i < 5;i++)
		for (int j = i + 1;j < 6;j++)
			EXPECT_GE(v[i], v[j]);
	for (int i = 0;i < sizeof(v) / sizeof(v[0]);i++)
		cout << v[i] << " ";
}