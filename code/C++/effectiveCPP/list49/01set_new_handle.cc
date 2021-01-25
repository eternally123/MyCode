#include <iostream>
using namespace std;

void outOfMem()
{
    cerr << "out of memory\n";
    abort();
}

int main()
{
    set_new_handler(outOfMem);
    int *parray = new int[10000000000000L];
}