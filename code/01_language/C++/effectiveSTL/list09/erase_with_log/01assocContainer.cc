#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool judge(int v)
{
    if (v > 0)
        return true;
    else
        return false;
}

void print(set<int> &v)
{
    for (auto &it : v)
        cout << it << " ";
}

int main()
{
    set<int> v;
    for (int i = -50; i < 50; i++)
    {
        v.insert(i);
    }

    for (auto it = v.begin(); it != v.end();)
    {
        if (judge(*it))
        {
            cout << "erase " << *it << endl; // do log
            v.erase(it++);
        }
        else
        {
            ++it;
        }
    }

    print(v);
}

/**
 * 对于需要做日志的关联容器删除，可以用遍历的方式。但是注意it++
**/