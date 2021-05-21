#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

int main()
{
    cout << thread::hardware_concurrency() << endl; //输出CPU核心数
    // cout << this_thread::get_id() << endl;
}