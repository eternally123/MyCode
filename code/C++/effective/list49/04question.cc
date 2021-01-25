#include <iostream>
#include <new>

using namespace std;

static int count = 0;
void badAlloc()
{
    cout << "bad alloc:" << count << endl;
}

int main()
{
    set_new_handler(badAlloc);
    int *p = nullptr;
    while (1)
    {
        p = new int;
        count++;
    }
    if (p == nullptr)
        cout << "nullptr\n";
}