#include <iostream>
#include <map>
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
    map<int, Widget> m;
    {
        m[1] = Widget();
    }
    cout << "===============\n";
    {
        auto p = pair<int, Widget>(2, Widget());
        cout << "===============\n";
        m.insert(p);
    }
    cout << "===============\n";
    {
        auto p = map<int, Widget>::value_type(3, Widget()); //如果这里改用一条语句，则insert时不会调用copy constructor，会调用move constructor
        m.insert(p);
    }
    cout << "===============\n";
}
/**
 * constructor   
 * constructor    前面两个是Widget构造函数与m[1]中widget构造函数
 * operator=      赋值运算符为m[1]赋值
 * destructor     析构widget局部对象
 * ===============
 * constructor        构造对象Widget
 * move constructor   移动构造插入
 * destructor         析构局部对象widget()
 * ===============
 * copy constructor    insert时调用拷贝构造
 * destructor          析构局部对象p
 * ===============
 * constructor         构造对象widget
 * move constructor    移动构造map::value_type
 * destructor          析构widget
 * copy constructor    拷贝构造p，insert
 * destructor          析构p
 * ===============
 * destructor           析构map中的两个对象
 * destructor           
 **/