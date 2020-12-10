#include <iostream>

using namespace std;

class Constructor
{
public:
    Constructor() { cout << "constructor\n"; }
    // Constructor(Constructor &mc) { cout << "copy constructor\n"; }
    Constructor(const Constructor &mc) { cout << "copy constructor\n"; }
    // Constructor(Constructor &&mc) { cout << "move constructor\n"; }
    Constructor(const Constructor &&mc) { cout << "move constructor\n"; }

    void print() { cout << "print\n"; }
};

void test1(Constructor &c)
{
    Constructor cc = move(c);
    cout << &cc << endl;
}

void test2(Constructor &&c)
{
    cout << &c << endl;
    Constructor cc = move(c);
    cout << &cc << endl;
}

int main()
{
    Constructor c;
    cout << &c << endl;
    test1(c);
    test2(move(c));
    cout << &c << endl;

    cout << is_rvalue_reference<decltype(move(c))>::value << endl;
}