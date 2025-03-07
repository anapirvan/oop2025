
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
        ok=v.Add(x);
        if (ok == false)
            i = n;
    }
    v.Sort();
    v.Print();
}

