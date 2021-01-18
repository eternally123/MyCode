#include <stdio.h>

char hello_world(int num)
{
    printf("hello %d!!\n", num);
    return (char)num + 1;
}