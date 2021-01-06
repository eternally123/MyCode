#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

int main()
{
    cout << thread::hardware_concurrency() << endl;
    // cout << this_thread::get_id() << endl;
}