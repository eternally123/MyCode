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
    int e_mytest; //该变量在程序运行时临时放在栈中
    e_mytest = 9;
    return 0;
}

/**
 * g++ main.cc -o main
 * nm main
 * 可以查看到全局变量存放的位置
 **/