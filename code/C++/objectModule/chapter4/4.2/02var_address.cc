#include <iostream>
#include <time.h>

using namespace std;

int *ptest = new int(120);
int g1;
int g2;

int g3 = 12;
int g4 = 32;
int g5;
int g6 = 0;
static int g7;
static int g8 = 0;
static int g9 = 10;
void mygfunc()
{
    return;
}
//定义一个类
class MYACLS
{
public:
    int m_i;
    static int m_si; //这是声明不是定义
    int m_j;
    static int m_sj;
    int m_k;
    static int m_sk;
};
int MYACLS::m_sj = 12; //这才是定义

int main()
{
    printf("ptest地址=%p\n", &ptest);
    printf("g1地址=%p\n", &g1);
    printf("g2地址=%p\n", &g2);
    printf("g3地址=%p\n", &g3);
    printf("g4地址=%p\n", &g4);
    printf("g5地址=%p\n", &g5);
    printf("g6地址=%p\n", &g6);
    printf("g7地址=%p\n", &g7);
    printf("g8地址=%p\n", &g8);
    printf("g9地址=%p\n", &g9);
    printf("MYACLS::m_sj地址=%p\n", &(MYACLS::m_sj));
    printf("mygfunc()地址=%p\n", mygfunc);
    printf("main()地址=%p\n", main);

    int i = 7;
    printf("i地址=%p\n", &i);
    return 0;
}

/**
 * g++ main.cc & ./a.out
 * 
 * 运行结果
 * ptest地址=0x56240e74d028
 * g1地址=0x56240e74d030
 * g2地址=0x56240e74d034
 * g3地址=0x56240e74d010
 * g4地址=0x56240e74d014
 * g5地址=0x56240e74d038
 * g6地址=0x56240e74d03c
 * g7地址=0x56240e74d044
 * g8地址=0x56240e74d048
 * g9地址=0x56240e74d018
 * MYACLS::m_sj地址=0x56240e74d01c
 * mygfunc()地址=0x56240e74a1c9
 * main()地址=0x56240e74a1d4
 * i地址=0x7fffc90817f4
 * 
 * 结论：
 * ①没有初值或初值为0的全局变量聚在一起(g1、g2、g5和g6、g7、g8)
 * ②有初值的全局变量聚在一起(g3、g4、g9)
 * ③全局变量和函数的地址比较相近(gx、main、myfunc)，局部变量不是(i)
 * 
 * Q：
 * 全局变量放到数据段哪儿了？为什么和函数地址比较相近？
 * 局部变量又放到栈哪儿了？
 * 数据段和栈的区别？
 * 全局变量的地址到底会不会变(书上说不变，Linux实验会变)？这个地址指的是什么地址？
 **/