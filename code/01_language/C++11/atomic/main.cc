#include <iostream>
#include <atomic>

using namespace std;

int main()
{
    atomic<int> total{0}; // 初始化不能用=赋值
    total = 1;            // 相当于atomic_store(&total, 0);
    total++;
    cout << total << endl;

    // atomic<int64_t> total;
    // atomic_store(&total, (long)0);
    // total++;
    // cout << total << endl;
}