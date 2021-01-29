#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool sortFunc(const int &num1, const int &num2)
{
    if (num1 > num2)
        return true;
    else
        return false;
}

int main()
{
    vector<int> v;
    for (int i = 1; i < 10; i++)
        v.push_back(i);
    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    partial_sort(v.begin(), v.begin() + 5, v.end(), sortFunc);
    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

/**
 * 对于比较函数的理解：
 * 比较函数最后都以less than的形式排序。
 * 比较函数中，如果first is less than second，应该返回true。否则返回false
 * 
 * sort partial_sort nth_element都是非稳定排序算法
 **/