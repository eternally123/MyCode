#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <random>
#include <functional>

using namespace std;

int main()
{
    // 以随机数填充 vector
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dis(0, 9);

    vector<int> v1(10), v2(10);
    generate(v1.begin(), v1.end(), bind(dis, ref(mt)));
    generate(v2.begin(), v2.end(), bind(dis, ref(mt)));

    // 排序
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // 输出 v1
    cout << "v1 : ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // 输出 v2
    cout << "v2 : ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // 归并
    vector<int> dst;
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(dst));

    // 输出
    cout << "dst: ";
    copy(dst.begin(), dst.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
}

/**
 * 归并二个相继的已排序范围 [first, middle) 及 [middle, last) 为一个已排序范围 [first, last) 。
 * 若对于任何指向序列的迭代器 it 与任何使得 it + n 为指向序列元素的合法迭代器的非负整数 n ， 
 * comp(*(it + n), *it) 求值为 false ，则称序列 [first, last) 相对于 comp 已排序。
 * 
 * 此归并是稳定的，
 * 意思是对于原先二个范围中的等价元素。
 * 来自第一范围的元素（保持其原顺序）先于来自第二范围的元素（保持其原顺序）。
 **/