#include <iostream>
#include "Array.h"
using namespace std;

int compara(const int& a, const int& b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    return -1;
}

int main()
{
   
    Array<int> a1;
    a1 += 2;
    a1 += 10;
    a1 += 3;

    cout << a1[2] << '\n';
    cout << a1[8] << '\n';

    a1.Insert(1, 10);
    a1.Delete(0);
    cout << '\n';
    a1.Delete(10);
    cout << '\n';

    ArrayIterator<int> it = a1.GetBeginIterator();
    ArrayIterator<int> ultimul = a1.GetEndIterator();
    cout << '\n';
    while (it != ultimul)
    {
        cout << *(it.GetElement()) << " ";
        it++;
    }

   
    Array<int> a2 = a1;

    a2.Insert(15, a1);
    a2.Insert(24, a1);
    cout << '\n';
    a2.Insert(10, 67);
    cout << '\n';
    ArrayIterator<int> it2 = a2.GetBeginIterator();
    ArrayIterator<int> ultimul2 = a2.GetEndIterator();
    cout << '\n';
    while (it2 != ultimul2)
    {
        cout << *(it2.GetElement()) << " ";
        it2++;
    }
    cout << '\n';

  
    a1 = a2;
    ultimul = a1.GetEndIterator();
    for (it = a1.GetBeginIterator(); it != ultimul; it++)
    {
        cout << *(it.GetElement()) << " ";
    }
    cout << '\n';

    
    Compara2 cmp;
    a1.Sort(&cmp);
    ultimul = a1.GetEndIterator();
    for (it = a1.GetBeginIterator(); it != ultimul; it++)
    {
        cout << *(it.GetElement()) << " ";
    }
    cout << '\n';

    cout << a1.BinarySearch(10) << '\n';
    cout << a1.BinarySearch(9, compara) << '\n';
    cout << a1.BinarySearch(100, &cmp) << '\n';


    cout << a1.Find(10) << '\n';
    cout << a1.Find(9, compara) << '\n';
    cout << a1.Find(100, &cmp) << '\n';

    cout << a1.GetSize() << " " << a1.GetCapacity();

}

