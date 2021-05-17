#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v;
    v.reserve(5);
    v[1] = 3;
    v[4] = 5;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}