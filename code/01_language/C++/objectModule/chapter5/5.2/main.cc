/**
 * 静态成员函数调用方法
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

    static void mystfunc()
    {
        printf("mystfunc()被调用\n");
    }
};

int main()
{
    MYACLS myacls;
    myacls.mystfunc();
    MYACLS *pmyacls = new MYACLS;
    pmyacls->mystfunc();
    ((MYACLS *)0)->mystfunc(); //这样调用静态成员函数没问题
    ((MYACLS *)0)->myfunc(12); //这样调用非静态成员函数，this指针就是0，如果不访问成员变量也没有问题。
    pmyacls->mystfunc();
    printf("MYACLS::mystfunc()地址 = %p\n", MYACLS::mystfunc);
    cout << "断点设置在这里" << endl;
    delete pmyacls;
}

/**
 * 对静态成员函数的调用，无论用对象名还是对象指针，效果一样。
 * 都会被编译器转换为一般的针对普通成员函数的调用形式。
 * 
 * 静态成员函数的调用不会被插入this指针。
 **/