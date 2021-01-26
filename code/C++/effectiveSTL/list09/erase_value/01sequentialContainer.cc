#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &v)
{
    for (auto &it : v)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
        v.push_back(i);
    }

    v.erase(remove(v.begin(), v.end(), 50), v.end());
    print(v);
}

/**
 * 对于顺序容器，删除特定值可以用erase-remove
 **/