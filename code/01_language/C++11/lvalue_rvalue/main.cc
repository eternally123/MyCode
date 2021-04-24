#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A()\n"; };
    A(const A &) { cout << "A(const&)\n"; }
    // A(A &) { cout << "A(&)\n"; }
    A(A &&) { cout << "A(&&)\n"; }
    // A(const A &&) { cout << "A(const&&)\n"; }
    ~A() { cout << "~A()\n"; };
    int num = 10;
};

int main()
{
    int n = 10;
}
/**
 **/