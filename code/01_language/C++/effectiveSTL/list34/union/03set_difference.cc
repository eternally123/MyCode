#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
auto print = [](const auto &v, const char *end = "") {
    cout << "{ ";
    for (auto i : v)
        cout << i << ' ';
    cout << "} " << end;
};

struct Order // 拥有某些有趣数据的类
{
    int order_id;
};

ostream &operator<<(ostream &os, const Order &ord)
{
    return os << "order=" << ord.order_id << ',';
}

int main()
{
    const vector<int> v1{1, 2, 5, 5, 5, 9};
    const vector<int> v2{2, 5, 7};
    vector<int> diff;

    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                   inserter(diff, diff.begin()));
    print(v1, "\\");
    print(v2, "=");
    print(diff, "\n");

    // 我们想知道那些顺序在旧和新状态之间“改变了”：
    vector<Order> old_orders{{1}, {2}, {5}, {9}};
    vector<Order> new_orders{{2}, {5}, {7}};
    vector<Order> changed_orders;

    set_difference(old_orders.begin(), old_orders.end(),
                   new_orders.begin(), new_orders.end(),
                   back_inserter(changed_orders),
                   [](auto &a, auto &b) { return a.order_id < b.order_id; });

    cout << "old orders = ";
    print(old_orders, "\n");
    cout << "new orders = ";
    print(new_orders, "\n");
    cout << "changed    = ";
    print(changed_orders, "\n");
}
/**
 * 复制来自已排序范围 [first1, last1) 并且不在已排序范围 [first2, last2) 中找到的元素到始于d_first的范围。
 * 结果范围亦已排序。
 * 
 * 单独对待等价元素，即若某元素在 [first1, last1) 中找到 n 次而在 [first2, last2) 中找到 m 次，
 * 则准确复制它 std::max(n-m, 0) 次到 d_first 。结果范围不能与任一输入范围重叠。
 **/
