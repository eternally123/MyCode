#include <iostream>
using namespace std;

void outOfMem1();
void outOfMem2();

void outOfMem1()
{
    cerr << "out of memory1\n";
    throw bad_alloc();
}

void outOfMem2()
{
    cerr << "out of memory2\n";
}

int main()
{
    set_new_handler(outOfMem1);
    try
    {
        int *parray = new int[10000000000000L];
    }
    catch (bad_alloc)
    {
        cout << "bad alloc\n";
    }
    cout << "finish\n";
}