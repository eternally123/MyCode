#include <stdio.h>

int *hello_world(int *num)
{
    printf("hello \n");
    printf("hello %d\n", *num);
    return num;
}