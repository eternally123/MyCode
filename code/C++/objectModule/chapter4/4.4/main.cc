#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class FAC
{
public:
    int m_fai;
    int m_faj;
};

//class MYACLS
class MYACLS : public FAC
{
public:
    int m_i;
    static int m_si; //这是声明不是定义
    int m_j;

public:
    void myfunc()
    {
        m_i = 5;
        m_j = 6;
    }
};
int MYACLS::m_si = 0; //这才是定义

int main()
{

    {
        MYACLS myobj;
        MYACLS *pmyobj = new MYACLS();
        cout << MYACLS::m_si << endl;
        cout << myobj.m_si << endl;
        cout << pmyobj->m_si << endl;

        MYACLS::m_si = 1;
        myobj.m_si = 2;
        pmyobj->m_si = 3;

        printf("myobj.m_i = %p\n", &myobj.m_i);
        printf("pmyobj->m_i = %p\n", &pmyobj->m_i);
        printf("MYACLS::m_si = %p\n", &MYACLS::m_si);
        printf("MYACLS::m_si = %p\n", &myobj.m_si);
        printf("MYACLS::m_si = %p\n", &pmyobj->m_si);

        pmyobj->myfunc();

        printf("MYACLS::m_i = %d\n", &MYACLS::m_i); //0
        printf("MYACLS::m_j = %d\n", &MYACLS::m_j); //4

        pmyobj->m_faj = 7; //给父类的成员变量赋值

        //cout << "设置断点" << endl;
    }

    return 0;
}

/**
 * 通过反汇编，可以看到，成员变量的存取：
 * ①对于静态成员变量：
 *      保存在数据段中，有自己的地址。按地址存取即可。
 * ②对于非静态成员变量：
 *      编译器隐式的将对其的访问添加了this指针。即this->xxx的访问形式。
 *      即用对象的首地址加上该成员变量的偏移量。
 *      偏移量是在编译时就计算好的，运行时访问的地址直接是this+4/8/xxx等这种形式。存取效率很高。
 *      即使存在继承关系，也会编译时计算好变量的偏移值。
 * 
 *      但是对于虚基类中的成员变量访问，以指针形式访问需要一些间接手段导致时间变慢。
 * 
 * 
 * Q：
 * 自己尝试反汇编查看验证
 **/