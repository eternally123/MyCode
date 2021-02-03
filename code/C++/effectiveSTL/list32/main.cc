#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i <= 10; i++)
        v.push_back(i);

    cout << v.size() << endl; // 11
    v[3] = v[5] = v[9] = 99;
    v.erase(remove(v.begin(), v.end(), 99), v.end());
    cout << v.size() << endl; // 8
}