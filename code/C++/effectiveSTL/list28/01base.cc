#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 1; i < 5; i++)
    {
        v.push_back(i);
    }

    auto rit = find(v.rbegin(), v.rend(), 3);
    cout << *rit << endl;
    auto it = rit.base();
    cout << *it << endl;
}

/**
 * 输出结果是 3 4
 * 
 * rbegin 与end有错位。rend与begin也有错位。
 * 相应的，rit与it也有错位
 * 
 * 插入时，正向迭代器在前面插入，反向迭代器在相对于反向迭代器的前面插入插入
 **/