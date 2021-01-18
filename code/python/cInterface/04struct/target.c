#include <stdio.h>
#include <string.h>
typedef struct
{
    char *ptr;
    float f;
    char array[10];
} target_struct;

target_struct *hello_world(target_struct *target)
{
    // printf("hello %s.%d!!\r\n",name,num[0]);
    printf("ptr=%p,f=%f,array=%p\n", target->ptr, target->f, target->array);

    static char temp = 0x30;
    target->ptr = &temp;
    target->f = 3.1;
    memset(target->array, 1, sizeof(target->array));
    return target;
}