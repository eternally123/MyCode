#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    A() {}
    ~A() {}

    int *p = new int;
    string str = "Fuck";
};

int main()
{
    A a;
    A b(std::move(a));
    cout << a.p << " " << a.str << " ";
    cout << b.p << " " << b.str << " ";
}

// 当定义了析构函数，就不会生成默认的移动构造函数
