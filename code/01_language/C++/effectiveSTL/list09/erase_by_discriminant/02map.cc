#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool judge(pair<int, int> p)
{
    if (p.first > 0)
        return false;
    else
        return true;
}

void print(map<int, int> &v)
{
    for (auto &it : v)
        cout << it.first << " ";
}

int main()
{
    map<int, int> v;
    for (int i = -50; i < 50; i++)
    {
        v[i] = i;
    }

    map<int, int> tmp;
    remove_copy_if(v.begin(), v.end(), inserter(tmp, tmp.end()), judge);
    v.swap(tmp);

    print(v);
}

/**
 * 对于map，删除特定条件的元素可以用remove_copy_if
**/