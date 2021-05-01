#include <iostream>
using namespace std;

void outOfMem1();
void outOfMem2();

void outOfMem1()
{
    cerr << "out of memory1\n";
    set_new_handler(outOfMem2);
    int *p = new int[100];
    // abort();
}

void outOfMem2()
{
    cerr << "out of memory2\n";
    set_new_handler(outOfMem1);
    int *p = new int[100];
    // abort();
}

int main()
{
    // set_new_handler(outOfMem1);
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