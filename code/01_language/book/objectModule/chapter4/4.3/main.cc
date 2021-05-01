#include <iostream>
#include <time.h>

using namespace std;

#pragma pack(1) //1字节对齐方式
class MYACLS
{
public:
    int m_i;
    static int m_si; //这是声明不是定义
    int m_j;
    static int m_sj;
    int m_k;
    static int m_sk;

public:
    char m_c; //1字节
    int m_n;  //4字节

private:
    int m_pria;
    int m_prib;

public:
    void printMemPoint() //因为要打印私有的成员变量偏移值，只能用成员函数打印
    {
        cout << "打印成员变量偏移值---------------" << endl;
        printf("MYACLS::m_i = %p\n", &MYACLS::m_i); //类名不要省略，必须要有，打印的才是偏移值，否则打印的就是对象的该成员变量的物理地址了
        printf("MYACLS::m_j = %p\n", &MYACLS::m_j);
        printf("MYACLS::m_k = %p\n", &MYACLS::m_k);
        printf("MYACLS::m_c = %p\n", &MYACLS::m_c);
        printf("MYACLS::m_n = %p\n", &MYACLS::m_n);

        printf("MYACLS::m_pria = %p\n", &MYACLS::m_pria);
        printf("MYACLS::m_prib = %p\n", &MYACLS::m_prib);
        cout << "------------------------" << endl;
    }

public:
    virtual void mfv() {}
};
#pragma pack()        //取消指定的1字节对齐，恢复缺省对齐（原来是多少就恢复成多少）
int MYACLS::m_sj = 0; //这才是定义

int main()
{

    MYACLS myobj;
    myobj.m_i = myobj.m_j = myobj.m_k = 0;
    cout << sizeof(myobj) << endl;
    printf("myobj.m_i = %p\n", &myobj.m_i);
    printf("myobj.m_j = %p\n", &myobj.m_j);
    printf("myobj.m_k = %p\n", &myobj.m_k);
    printf("myobj.m_c = %p\n", &myobj.m_c);
    printf("myobj.m_n = %p\n", &myobj.m_n);

    MYACLS *pmyobj = new MYACLS();
    printf("pmyobj->m_i = %p\n", &pmyobj->m_i);
    printf("pmyobj->m_j = %p\n", &pmyobj->m_j);
    printf("pmyobj->m_k = %p\n", &pmyobj->m_k);
    printf("pmyobj->m_c = %p\n", &pmyobj->m_c);
    printf("pmyobj->m_n = %p\n", &pmyobj->m_n);

    pmyobj->printMemPoint();

    int MYACLS::*mypoint = &MYACLS::m_n;
    printf("pmyobj->m_n偏移地址 = %p\n", mypoint); // 这里

    return 0;
}

/**
 * 结果：
 * 33
 * myobj.m_i = 0x7ffe0d019b58
 * myobj.m_j = 0x7ffe0d019b5c
 * myobj.m_k = 0x7ffe0d019b60
 * myobj.m_c = 0x7ffe0d019b64
 * myobj.m_n = 0x7ffe0d019b65
 * pmyobj->m_i = 0x565170a092c8
 * pmyobj->m_j = 0x565170a092cc
 * pmyobj->m_k = 0x565170a092d0
 * pmyobj->m_c = 0x565170a092d4
 * pmyobj->m_n = 0x565170a092d5
 * 打印成员变量偏移值---------------
 * MYACLS::m_i = 0x8
 * MYACLS::m_j = 0xc
 * MYACLS::m_k = 0x10
 * MYACLS::m_c = 0x14
 * MYACLS::m_n = 0x15
 * MYACLS::m_pria = 0x19
 * MYACLS::m_prib = 0x1d
 * ------------------------
 * pmyobj->m_n偏移地址 = 0x15
 * 
 * 结论：
 * ①成员变量地址按照定义的先后顺序排列。
 * ②public、private、protected等对变量地址没影响
 * ③pragma pack是用来指定字节对齐标准，默认是4byte
 * ④打印时，如果用对象成员变量地址就是实际地址，如果用类的成员变量地址就是偏移量
 * 
 **/