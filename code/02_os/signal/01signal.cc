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
    signal(SIGINT, handler);

    printf("Caught SIGINT, input 'quit' to exit...\n");
    int i = 0;
    while (1)
    {
        i++;
        if (i % 100000 == 0)
            i = 0;
    }
    printf("Exit...\n");
    return 0;
}