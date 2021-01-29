#include <iostream>
#include <set>

using namespace std;

struct intComp
{
    bool operator()(const int &i, const int &j) const
    {
        if (i * j > 0)
            return true; // 接受插入
        else
            return false; // 不接受插入
    }
};

int main()
{
    set<int, intComp> s; // 指定key_comp，true的时候符合标准
    s.insert(1);
    s.insert(-2);
    s.insert(2);
    s.insert(2);
    for (auto &it : s)
    {
        cout << it << " ";
    }

    // cout << endl;
    // auto iter = s.find(1);
    // if (iter != s.end())
    //     cout << *iter << endl;
}

/**
 * 利用的是operator<来做的，所以输出为2 2 1
 **/