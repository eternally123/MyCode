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

    transform(d.rbegin(), d.rend(), front_inserter(d), f);
    for (auto &it : d)
    {
        cout << it << " ";
    }
}

/**
 * inserter和迭代器顺序无关，不管是正向迭代器还是反向迭代器。都是在指定的位置插入，然后此位置元素后移
 **/