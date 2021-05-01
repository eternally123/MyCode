#include <iostream>
#include <set>

using namespace std;

struct intComp
{
    bool operator()(const int &i, const int &j) const
    {
        if (i * j > 0)
            return true;
        else
            return false;
    }
};

int main()
{
    set<int, intComp> s;
    s.insert(1);
    s.insert(-2);
    s.insert(2);
    for (auto &it : s)
    {
        cout << it << " ";
    }
}

/**
 * 利用的是operator<来做的，所以输出为2 1
 **/