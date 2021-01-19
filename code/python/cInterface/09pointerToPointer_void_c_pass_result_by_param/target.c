#include <stdio.h>
#include <stdlib.h>

void get(void **p)
{
    int *num = malloc(sizeof(int));
    *num = 10;
    void *ptr = (void *)num;
    *p = ptr;
}

void print(void **p)
{
    int *num = (int *)(*p);
    printf("hello world\n");
    printf("hello world address = %d\n", num);
    printf("hello world num = %d\n", *num);
    free(num);
    return;
}