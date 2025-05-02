

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class Comparator
{
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

int main()
{
    fstream fin("input.txt");
    string str;
    getline(fin, str);
    string delim(" ,.?!");

    map<string, int> m;
    
    int poz1 = str.find_first_not_of(delim, 0);
    int poz2 = str.find_first_of(delim, 0);

    while (poz1 != string::npos and poz2 != string::npos)
    {
        string cuv = str.substr(poz1, poz2 - poz1);
        for (int i = 0;i < cuv.size();i++)
            cuv[i] = tolower(cuv[i]);
        m[cuv]++;
        poz1 = str.find_first_not_of(delim, poz2);
        poz2 = str.find_first_of(delim, poz1);
    }

    map<string, int>::iterator it;
    /*for (it = m.begin();it != m.end();it++)
        cout << it->first << " " << it->second << "," << endl;*/

    priority_queue<pair<string, int>, vector<pair<string, int>>, Comparator> pr_queue;
    for (it = m.begin();it != m.end();it++)
        pr_queue.push(*it);

    while (pr_queue.empty() == false)
    {
        cout << pr_queue.top().first << "=>" << pr_queue.top().second << endl;
        pr_queue.pop();
    }


    
}

