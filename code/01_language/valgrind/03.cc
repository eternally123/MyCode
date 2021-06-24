#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* p = (char*)malloc(4);
    *p = 'a';
    char c = *p;
    printf("\n [%c]\n", c);
    //     static char* q = p + 1;

    return 0;
}