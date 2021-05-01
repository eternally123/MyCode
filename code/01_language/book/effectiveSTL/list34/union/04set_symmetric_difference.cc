#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v2{5, 7, 9, 10};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> v_symDifference;

    set_symmetric_difference(
        v1.begin(), v1.end(),
        v2.begin(), v2.end(),
        back_inserter(v_symDifference));

    for (int n : v_symDifference)
        cout << n << ' ';
}
/**
 * 计算二个已排序范围的对称差：
 * 复制在任一范围中，但不在两个范围中找到的元素，到始于 d_first 的范围。结果范围亦为已排序。
 * 
 * 若某元素在 [first1, last1) 中找到 m 次而在 [first2, last2) 中找到 n 次，
 * 则将准确复制它 std::abs(m-n) 次到 d_first 。
 * 若 m>n ，则从 [first1,last1) 复制末尾的 m-n 个元素，
 * 否则从 [first2,last2) 复制末尾的 n-m 个元素。结果范围不能与任一输入范围重叠。
 **/
