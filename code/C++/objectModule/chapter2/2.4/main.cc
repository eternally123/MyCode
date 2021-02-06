#include <iostream>

using namespace std;

// class M0TX
// {
// public:
//     M0TX() //默认构造函数
//     {
//         cout << "Ogood!" << endl;
//     }
// };

// class MATX
// {
// public:
//     MATX() //默认构造函数
//     {
//         cout << "good HAHAHA" << endl;
//     }
// };

class MBTXPARENT
{
public:
    MBTXPARENT() { cout << "MBTXPARENT()执行了\n"; }
};

class MBTX : public MBTXPARENT
{
public:
    int m_i;
    int m_j;

    void funct()
    {
        cout << "I am very good" << endl;
    }
};

int main()
{
    MBTX myb;
}

/**
 * 执行结果：
 * good HAHAHA
 * Ogood!
 * 
 * 变量初始化顺序与声明顺序一致
 **/