#include <stdio.h>

int hello_world(void (*func)())
{
    printf("before callback\n");
    func();
    printf("after callback\n");
    return 0;
}
