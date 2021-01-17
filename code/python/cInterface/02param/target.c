#include <stdio.h>

char hello_world(int num)
{
    printf("hello %d!!\r\n", num);
    return (char)num + 1;
}