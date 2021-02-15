/**
 * 虚成员函数调用方法
 **/
#include <iostream>
using namespace std;

class MYACLS
{
public:
    int m_i;
    void myfunc(int abc)
    {
        m_i += abc;
    }
    virtual void myvirfunc()
    {
        printf("myvirfunc()被调用,this = %p\n", this);
        //myvirfunc2();
        // MYACLS::myvirfunc2();
    }
    virtual void myvirfunc2()
    {
        printf("myvirfunc2()被调用,this = %p\n", this);
    }
};

int main()
{
    MYACLS myacls;
    myacls.myvirfunc();
    MYACLS *pmyacls = new MYACLS;
    pmyacls->myvirfunc();
    delete pmyacls;
}

/**
 * 对虚成员函数调用有两种方式：
 *      一种是利用对象调用，无需经过虚表。
 *      一种是利用指针调用，需要利用虚表来调用。
 * 
 * 同时还要注意：
 *      如果是直接调用，则需要虚表；
 *      如果是通过类名::虚函数，则直接调用，无需虚表。
 **/