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

    nth_element(v.begin(), v.begin() + 4, v.end(), sortFunc);
    for (auto &it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

/**
 * 找到第n位数，让左边的都less than，右边的都more than
 * 是非稳定排序
 **/