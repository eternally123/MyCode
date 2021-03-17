#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v = {2, 1, 3, 4, 5};
    cout << find(v.begin(), v.end(), 5) - v.begin();
}