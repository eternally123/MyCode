#include <stdio.h>

int hello_world(void (*func)())
{
    printf("before callback\n");
    if (func == NULL)
        printf("null function\n");
    else
        func();
    printf("after callback\n");
    return 0;
}
