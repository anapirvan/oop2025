#include "NumberList.h"
#include <iostream>
using namespace std;
void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count] = x;
	count++;
	return true;
}

void NumberList::Sort()
{
	int i, sorted;
	do
	{
		sorted = 1;
		for(i=0;i<count-1;i++)
			if (numbers[i] > numbers[i + 1])
			{
				swap(numbers[i], numbers[i + 1]);
				sorted = 0;
			}
	} while (!sorted);

}

void NumberList::Print()
{
	for (int i = 0;i < count;i++)
		std::cout << numbers[i] << " ";
}