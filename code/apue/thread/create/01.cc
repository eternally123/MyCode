#include <iostream>

#include <unistd.h>
#include <pthread.h>

using namespace std;

int main()
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    cout << pid << endl;
    cout << tid << endl;
}