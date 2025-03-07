
#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
    NumberList v;
    v.Init();
    int i,x,n;
    bool ok ;
    cin >> n; 
    for (i = 0;i < n;i++)
    {
        cin >> x;
        v.Add(x);
    }
    v.Sort();
    v.Print();
}

