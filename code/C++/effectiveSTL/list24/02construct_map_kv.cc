#include <iostream>
#include <map>
#include <typeinfo>
using namespace std;

class Widget
{
public:
    Widget() { cout << "constructor\n"; }
    Widget(const Widget &w) { cout << "copy constructor\n"; }
    Widget(Widget &&w) { cout << "move constructor\n"; }
    ~Widget() { cout << "destructor\n"; }

    Widget &operator=(const Widget &w) { cout << "operator=\n"; }
};

int main()
{
    map<int, int> m;
    auto m1 = std::make_pair<int, int>(1, 1); // make_pair源码中调用的是pair函数
    auto m2 = std::pair<int, int>(1, 1);
    auto m3 = map<int, int>::value_type(1, 1); // value_type就是std::pair的别名
    m.insert(m1);
    m.insert(m2);
    m.insert(m3);
    for (auto &it : m)
    {
        cout << it.second << endl;
    }
}
/**
 *       
 **/