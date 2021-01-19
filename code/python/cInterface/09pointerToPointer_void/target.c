#include <stdio.h>

int **hello_world(void **num)
{
    printf("hello \n");
    printf("hello %d\n", **(int **)num);
    return num;
}