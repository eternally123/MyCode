#include <stdio.h>
#include <string.h>

void hello_world(char *buf, int size)
{
    printf("memset begin\n");
    memset(buf, 1, size);
    printf("memset finish\n");
}