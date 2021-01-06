#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

class Buffer
{
public:
private:
    mutex mu;
    condition_variable cond_put;
    condition_variable cond_get;
};

int main()
{

    this_thread::sleep_for(chrono::seconds(2));
}

//