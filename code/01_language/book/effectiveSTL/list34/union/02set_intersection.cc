#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 5, 6, 7, 8};
    vector<int> v2{5, 5, 7, 9, 10};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> v_intersection;

    set_intersection(v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     back_inserter(v_intersection));
    for (int n : v_intersection)
        cout << n << ' ';
}
/**
 * 构造始于 d_first ，
 * 由在两个已排序范围 [first1, last1) 与 [first2, last2) 中都找到的元素构成的已排序范围。
 * 若某元素在 [first1, last1) 中找到 m 而在 [first2, last2) 中找到 n 次，
 * 则从第一范围复制首 std::min(m, n) 个元素到目标范围。保持等价元素的顺序。
 * 结果范围不能与任一输入范围重叠。
 **/
