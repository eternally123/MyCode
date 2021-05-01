#include <iostream>

using namespace std;

class MATX
{
public:
    MATX() //默认构造函数
    {
        cout << "good HAHAHA" << endl;
    }
};

class MBTX
{
public:
    int m_i;
    int m_j;
    MATX ma;

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
 **/