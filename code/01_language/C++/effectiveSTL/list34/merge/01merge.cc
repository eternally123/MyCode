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
 * 归并二个已排序范围 [first1, last1) 和 [first2, last2) 到始于 d_first 的一个已排序范围中。
 * 若对于任何指向序列的迭代器 it 与任何使得 it + n 为指向序列元素的合法迭代器的非负整数 n ， 
 * comp(*(it + n), *it) 求值为 false ，则称序列相对于 comp 已排序。
 **/