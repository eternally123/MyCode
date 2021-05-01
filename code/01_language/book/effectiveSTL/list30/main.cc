#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int f(int x)
{
    return x * 10;
}

int main()
{
    deque<int> d;
    for (int i = 1; i < 5; i++)
    {
        d.push_back(i);
    }

    transform(d.rbegin(), d.rbegin() + 1, inserter(d, d.begin()), f);
    for (auto &it : d)
    {
        cout << it << " ";
    }
}