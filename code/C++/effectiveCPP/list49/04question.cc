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
        p = new int[2];
        count++;
    }
    if (p == nullptr)
        cout << "nullptr\n";
}

/**
 * 当设置了new handler
 * 
 * 当/proc/sys/vm/overcommit_memory为0时，即有OOM机制时，
 *  会被killed，137错误码
 * 
 * 
 * 当/proc/sys/vm/overcommit_memory为2时，即无OOM机制时，
 *  会一直返回bad_alloc。count数值也不变。（即和malloc现象相同）
 **/