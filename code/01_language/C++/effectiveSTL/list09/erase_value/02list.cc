#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void print(list<int> &v)
{
    for (auto &it : v)
    {
        cout << it << " ";
    }
}

int main()
{
    list<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
        v.push_back(i);
    }

    v.remove(50);
    print(v);
}

/**
 * 对于顺序容器list，删除特定值可以用remove更高效
 **/