#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void print(map<int, int> &v)
{
    for (auto &it : v)
    {
        cout << it.first << " ";
    }
}

int main()
{
    map<int, int> v;
    for (int i = 0; i < 100; i++)
    {
        v[i] = i;
    }

    v.erase(50);

    print(v);
}

/**
 * 对于关联容器，删除特定值可以用erase成员函数
**/