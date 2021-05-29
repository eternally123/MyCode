#include <iostream>
#include <thread>
using namespace std;

int f(int *i)
{
    for (int j = 0; j < 1000000; ++j)
        ++*i; // 虽然是addl，但是CPU内部会转换成微码，也是RISC风格的，也不是原子操作
}

int main()
{
    voliate int i = 0;
    thread t1 = thread(f, &i);
    thread t2 = thread(f, &i);
    t1.join();
    t2.join();
    cout << i << endl;
}
