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
        v.push_back(i);

    cout << binary_search(v.begin(), v.end(), 5, Comp) << endl;  // bool true
    cout << binary_search(v.begin(), v.end(), 20, Comp) << endl; // bool false
}
