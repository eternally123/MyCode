#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool judge(int v)
{
    if (v > 0)
        return false;
    else
        return true;
}

void print(vector<int> &v)
{
    for (auto &it : v)
        cout << it << " ";
}

int main()
{
    vector<int> v;
    for (int i = -50; i < 50; i++)
    {
        v.push_back(i);
    }

    v.erase(remove_if(v.begin(), v.end(), judge), v.end());

    print(v);
}

/**
 * 对于顺序容器，用erase成员函数和remove_if移除
**/