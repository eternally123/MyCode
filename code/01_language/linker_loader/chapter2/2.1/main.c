/**
 * 编译连接过程
 **/
#include <stdio.h>

int main()
{
    printf("hello world\n");
    return 0;
}

/**
 * 预编译：gcc -E hello.c -o hello.i  
 *       cpp hello.c > hello.i
 *      预编译做了哪些事情
 * 
 * 编译：gcc -S hello.c/hello.i -o hello.s
 *     /usr/lib/gcc/i486-linux-gun/4.1/ccl hello.c/hello.i
 *      编译做了哪些事情
 * 
 * 汇编：as hello.s -o hello.o
 *     gcc -c hello.c/hello.i/hello.s -o hello.o
 * 
 * 链接：ld -static crt1.o crti.o crtbeginT.o hello.o 
 *      -start-group -lgcc -lgcc_eh -lc-end-group crtend.o crtn.o(未验证)
 **/