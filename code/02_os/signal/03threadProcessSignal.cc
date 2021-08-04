#include <bits/stdc++.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
using namespace std;

static void handler(int sig)
{
    cout << "process signal:" << this_thread::get_id() << endl;
    printf("Recieved signal: %d\n", sig);
}

void threadFunc()
{
    cout << "threadID:" << this_thread::get_id() << endl;
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGALRM);
    sigprocmask(SIG_UNBLOCK, &sigset, NULL);
    signal(SIGALRM, handler);
    sleep(5);
}

int main(int argc, char* argv[])
{
    // 设置信号屏蔽字
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGALRM);
    sigprocmask(SIG_BLOCK, &sigset, NULL);

    cout << "main threadID:" << this_thread::get_id() << endl;

    alarm(1);
    thread t1(threadFunc);

    t1.join();
    // sleep(5);
}