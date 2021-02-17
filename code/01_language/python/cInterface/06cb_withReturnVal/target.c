#include <stdio.h>

int hello_world(int (*func)())
{
    printf("before callback\n");
    int ret = func();
    printf("after callback\tret=%d\n", ret);
    return 0;
}
