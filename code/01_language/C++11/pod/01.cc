// #include <iostream>
// #include <cstring>

// using namespace std;

// class T
// {
// public:
//     T(){};
//     virtual ~T(){};
//     virtual void print()
//     {
//         cout << "hello world" << endl;
//     }
//     int num;
// };

// int main()
// {
//     T t;
//     cout << sizeof(t) << endl;
//     memset(&t, 0, sizeof(t));
//     t.print();
// }

#include <iostream>
#include <memory.h>
using namespace std;

class parent
{
public:
    virtual void output();
    virtual void output2();
};

void parent::output()
{
    cout << "parent output" << endl;
}

void parent::output2()
{
    cout << "parent output2" << endl;
}

class son : public parent
{
public:
    void output();
};

void son::output()
{
    cout << "son" << endl;
}

int main()
{
    son s;
    memset(&s, 0, sizeof(s));                  // 会段错误
    cout << "sizeof(s)=" << sizeof(s) << endl; // 输出为8 没虚函数时1
    parent &p = s;
    p.output();
    return 0;
}

// 对于非POD类型，不要用memset或memcpy等进行赋值拷贝