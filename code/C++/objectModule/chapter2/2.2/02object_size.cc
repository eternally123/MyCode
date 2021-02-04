#include <iostream>
using namespace std;

class MyObj
{
public:
    MyObj(){};
    virtual ~MyObj(){};
    float getvalue() const {};
    static int s_getcount(){};
    virtual void vfunc(){};

private:
    float m_myvalue;
    static int m_scount;
};

int main()
{
    MyObj obj;
    cout << sizeof(obj) << endl; // 16
}