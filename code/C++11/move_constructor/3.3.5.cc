#include <iostream>

using namespace std;

class Constructor
{
public:
    Constructor() { cout << "constructor\n"; }
    ~Constructor() { cout << "~constructor\n"; }
    Constructor(Constructor &mc) { cout << "copy constructor\n"; }
    Constructor(const Constructor &mc) { cout << "copy constructor\n"; }
    Constructor(Constructor &&mc) { cout << "move constructor\n"; }
    // Constructor(Constructor &&) = delete;

    void print() { cout << "print\n"; }
    int i;
};

Constructor set(Constructor c)
{
    Constructor cc = move(c);
    cc.i = 10;
    cout << cc.i << endl;
    c.i = 100;
    cout << cc.i << endl;
    cout << &c << endl;
    cout << &cc << endl; // ?为什么地址不一样
}

int main()
{
    Constructor c;
    set(c);
}