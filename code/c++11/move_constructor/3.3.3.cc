#include <iostream>

using namespace std;

class Constructor
{
public:
    Constructor()
    {
        cout << "constructor\n";
        num = 0;
    }
    ~Constructor() { cout << "~constructor\n"; }
    Constructor(Constructor &mc) { cout << "copy constructor\n"; }
    Constructor(const Constructor &mc) { cout << "copy constructor\n"; }
    Constructor(Constructor &&mc)
        : num(mc.num)
    {
        cout << "move constructor\n";
        num++;
    }
    Constructor(const Constructor &&mc)
        : num(mc.num)
    {
        cout << "move constructor\n";
        num++;
    }
    // Constructor(Constructor &&) = delete;
    // Constructor(const Constructor &&) = delete;

    void print() { cout << "print\n"; }
    int num;
};

Constructor get()
{
    Constructor c;
    cout << &c << endl;
    // return move(c); // move将左值转为右值，但是移动构造被删除的话就会报错
    return c; // ？将亡值还是左值？调用移动构造函数。如果被delete，则调用拷贝构造函数。
}

int main()
{
    // get();

    Constructor c = get(); // 为什么调用移动构造函数不打印内容？ 编译器做了优化 -fno-elide-constructors
    cout << &c << endl;
    cout << c.num << endl; // 优化与否决定了num的值
}