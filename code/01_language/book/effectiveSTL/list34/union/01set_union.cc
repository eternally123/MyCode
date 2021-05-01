#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 2, 3, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 6, 7};
    vector<int> dest1;

    set_union(v1.begin(), v1.end(),
              v2.begin(), v2.end(),
              back_inserter(dest1));

    for (const auto &i : dest1)
    {
        cout << i << ' ';
    }
    cout << '\n';
}
/**
 * 构造始于 d_first ，
 * 由存在于一或两个已排序范围 [first1, last1) 和 [first2, last2) 中的所有元素构成的已排序范围。
 * 
 * 若某元素在 [first1, last1) 中找到 m 次并在 [first2, last2) 中找到 n 次，
 * 则将从 [first1, last1) 保持顺序复制全部 m 个元素到 d_first ，
 * 并从 [first2, last2) 保持顺序复制 std::max(n-m, 0) 个元素到 d_first 。
 **/
