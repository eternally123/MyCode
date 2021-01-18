#include <stdio.h>

int hello_world(int (*func)(int))
{
    printf("before callback\n");
    int ret = func(-10);
    printf("after callback\tret=%d\n", ret);
    return 0;
}
