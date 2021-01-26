#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool judge(int v)
{
    if (v > 0)
        return true;
    else
        return false;
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

    for (auto it = v.begin(); it != v.end();)
    {
        if (judge(*it))
        {
            cout << "erase " << *it << endl; // do log
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }

    print(v);
}

/**
 * 对于需要做日志的顺序容器删除，可以用遍历的方式。但是注意记录erase成员函数返回值
**/