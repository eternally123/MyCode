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

/**
 * ~/user/code/MyCode/code/C++/effectiveCPP/list49(master*) # ./a.out             root@server102
 * out of memory 
 * [1]    10095 abort (core dumped)  ./a.out

 **/