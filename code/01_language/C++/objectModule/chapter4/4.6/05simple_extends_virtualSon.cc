#include <iostream>
using namespace std;
// #pragma pack(1)
class Base
{
public:
    int m_bi;
};

class MYACLS : public Base
{
public:
    int m_i;
    int m_j;
    virtual void print() {}
};
// #pragma pack()

int main()
{
    cout << sizeof(MYACLS) << endl;              //24
    printf("MYACLS:m_bi = %d\n", &MYACLS::m_bi); //0
    printf("MYACLS:m_i = %d\n", &MYACLS::m_i);   //12
    printf("MYACLS:m_j = %d\n", &MYACLS::m_j);   //16
}

/**
 * 单一继承父类带虚函数、子类也带有虚函数的数据成员分布
 * 
 * 疑问？
 * 为什么不是0、16、20？vptr不是8字节吗？
 **/