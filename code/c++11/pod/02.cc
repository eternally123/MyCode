#include <iostream>

class T
{
public:
    // T() {} // 如果有非平凡构造函数....就不是POD
};

union M
{
    T t; // T如果有非平凡构造、析构、赋值、拷贝、移动等，就会删除union的默认构造
    int num;
};

int main()
{
    M m;
}