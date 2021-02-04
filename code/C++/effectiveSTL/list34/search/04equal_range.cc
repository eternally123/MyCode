#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(int a, int b)
{
    return a < b;
}

int main()
{
    vector<int> v;
    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i);
        v.push_back(i);
    }

    auto iter = equal_range(v.begin(), v.end(), 1, Comp);
    cout << iter.first - v.begin() << " " << iter.second - v.begin() << endl;
}
