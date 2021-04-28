#include <stdio.h>
#include <string>

void my_init(void)
{
    printf("my init\n");
}

typedef void (*ctor_t)(void);
ctor_t __attribute__((section(".ctors"))) my_init_p1 = &my_init;
ctor_t __attribute__((section(".ctors"))) my_init_p2 = &my_init;

int main()
{
    printf("hello world\n");
}