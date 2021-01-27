#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool judge(int v)
{
    if (v > 0)
        return false;
    else
        return true;
}

void print(list<int> &v)
{
    for (auto &it : v)
        cout << it << " ";
}

int main()
{
    list<int> v;
    for (int i = -50; i < 50; i++)
    {
        v.push_back(i);
    }

    // v.erase(remove_if(v.begin(), v.end(), judge), v.end());
    v.remove_if(judge);

    print(v);
}

/**
 * 对于顺序容器中的list，用remove_if成员函数更好
**/