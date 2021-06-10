#include <stdio.h>
#include <string.h>
#include <signal.h>

static void
handler(int sig)
{
    printf("Recieved signal: %d\n", sig);
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        kill(1990, 40);
    }
    return 0;
}