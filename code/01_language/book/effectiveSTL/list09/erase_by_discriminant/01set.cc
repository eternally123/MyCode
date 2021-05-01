#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool judge(int value)
{
    if (value > 0)
        return false;
    else
        return true;
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

    set<int> tmp;
    remove_copy_if(v.begin(), v.end(), inserter(tmp, tmp.end()), judge);
    v.swap(tmp);

    print(v);
    cout << endl;
    print(tmp);
}

/**
 * 对于set，删除特定条件的函数
**/