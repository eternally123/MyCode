#include <iostream>
#include <new>

using namespace std;

void badAlloc()
{
    cout << "bad alloc\n";
}

int main()
{
    // set_new_handler(badAlloc);
    int *p = new (nothrow) int[10000000000000L];
    if (p == nullptr)
        cout << "nullptr\n";
}