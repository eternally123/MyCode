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
};

int main()
{
    Constructor mc;
    Constructor mcc = move(mc);
}