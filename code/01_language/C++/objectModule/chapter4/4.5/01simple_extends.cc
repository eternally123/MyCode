#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class FAC //父类
{
public:
    int m_fai;
    int m_faj;
};
class MYACLS : public FAC //子类
{
public:
    int m_i;
    int m_j;

public:
    void print()
    {
        printf("MYACLS::m_i = %d\n", &FAC::m_fai);
        printf("MYACLS::m_i = %d\n", &FAC::m_faj);
        printf("MYACLS::m_i = %d\n", &MYACLS::m_fai);
        printf("MYACLS::m_i = %d\n", &MYACLS::m_faj);
        printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
        printf("MYACLS::m_j = %d\n", &MYACLS::m_j);
    }
};

int main()
{
    MYACLS m;
    m.print();
    return 0;
}

/**
 * 执行结果：
 * MYACLS::m_i = 0
 * MYACLS::m_i = 4
 * MYACLS::m_i = 0
 * MYACLS::m_i = 4
 * MYACLS::m_i = 8
 * MYACLS::m_j = 12
 * 
 * 可以看到：
 *      在单一继承下，一个对象包含的内容是其父类成员加上自己成员。(一般是先父类后子类，与编译器有关)
 *      (无关public、protected、private继承方式)
 **/