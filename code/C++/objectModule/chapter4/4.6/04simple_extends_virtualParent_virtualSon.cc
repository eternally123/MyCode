#include <iostream>
using namespace std;

class Base
{
public:
    virtual void mybvirfunc() {}
    int m_bi;
};

class MYACLS : public Base
{
public:
    int m_i;
    int m_j;
    virtual void print() {}
};

int main()
{
    cout << sizeof(MYACLS) << endl;              //24
    printf("MYACLS:m_bi = %d\n", &MYACLS::m_bi); //8
    printf("MYACLS:m_i = %d\n", &MYACLS::m_i);   //12
    printf("MYACLS:m_j = %d\n", &MYACLS::m_j);   //16
}

/**
 * 单一继承父类带虚函数、子类也带有虚函数的数据成员分布
 * 
 * 总结：
 * ①先是vptr(8byte)，然后父类成员变量，然后子类成员变量
 **/