#include <iostream>

namespace T
{
    struct A
    {
    };

    void ADD(A a)
    {
    }
}; // namespace T

int main()
{
    T::A a;
    ADD(a); //ADL 参数关联名称查找，会破坏隔离性，不要用
}