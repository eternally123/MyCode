#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int f(int x)
{
    return x * 10;
}

int main()
{
    deque<int> d;
    for (int i = 1; i < 5; i++)
    {
        d.push_back(i);
    }

    transform(d.begin(), d.end(), front_inserter(d), f);
    for (auto &it : d)
    {
        cout << it << " ";
    }
}

/**
 * 使用时注意transform不保证有足够的区间，需要指定inserter来完成类似于push_back或push_front的操作
 * 如果不用inserter而用迭代器，运行时就可能出现问题
 **/