#include <stdio.h>
#include <stdlib.h>

void *get()
{
    // int *num = malloc(sizeof(int));
    // *num = 97;
    char *num = malloc(10);
    memset(num, 'd', 10);

    void *ptr = (void *)num;
    return ptr;
}

void print(void *ptr)
{
    int *num = (int *)ptr;
    printf("hello world\n");
    printf("hello world address = %d\n", num);
    printf("hello world num = %d\n", *num);
    free(num);
    return;
}