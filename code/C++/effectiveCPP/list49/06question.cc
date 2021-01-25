#include <iostream>
#include <new>

using namespace std;

static int count = 0;
void badAlloc()
{
    cout << "bad alloc:" << count << endl;
    set_new_handler(nullptr);
}

int main()
{
    set_new_handler(badAlloc);
    int *p = nullptr;
    while (1)
    {
        p = new int[100000000L];
        count++;
    }
    if (p == nullptr)
        cout << "nullptr\n";
}