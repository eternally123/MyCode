#include <iostream>
using namespace std;

void outOfMem()
{
    cerr << "out of memory\n";
    // int *p = new int[100];
    // abort();
}

int main()
{
    set_new_handler(outOfMem);
    int *parray = new int[10000000000000L];
}

/**
 * 现象：一直打印out of memory
 **/