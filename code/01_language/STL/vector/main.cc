#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int> vv;
    for (int i = 0; i < 100; i++)
    {
        vv.push_back(i);
    }
    cout << v.size() << " " << v.capacity() << endl;
    cout << vv.size() << " " << vv.capacity() << endl;

    v.swap(vv);
    cout << v.size() << " " << v.capacity() << endl;
    cout << vv.size() << " " << vv.capacity() << endl;
    return 0;
}