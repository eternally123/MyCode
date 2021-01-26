#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    void *p = NULL;
    while (1)
    {
        p = NULL;
        p = malloc(sizeof(int) * 10000000);
        if (p == NULL)
            printf("nullptr\n");
        else
        {
            printf("address %p\n", p);
        }
    }
}
/**
 * https://cloud.tencent.com/developer/ask/88680/answer/155135
 **/