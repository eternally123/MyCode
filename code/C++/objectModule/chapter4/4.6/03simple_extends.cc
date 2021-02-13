#include <iostream>
using namespace std;

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
};

int main()
{
    cout << sizeof(MYACLS) << endl;              //12
    printf("MYACLS:m_bi = %d\n", &MYACLS::m_bi); //0
    printf("MYACLS:m_i = %d\n", &MYACLS::m_i);   //4
    printf("MYACLS:m_j = %d\n", &MYACLS::m_j);   //8
}

/**
 * 单一继承父类不带虚函数的数据成员分布
 **/