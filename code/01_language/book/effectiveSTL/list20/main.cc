#include <iostream>
#include <set>
#include <string>
using namespace std;

class MyClass
{
public:
    struct Compare
    {
        bool operator()(const string *ps1, const string *ps2) const
        {
            return *ps1 < *ps2;
            // return true的话，三个都被插入
            // return false的话，三个只有第一个被插入
        }
    };
};

int main()
{
    set<string *, MyClass::Compare> s;
    s.insert(new string("mac"));
    s.insert(new string("bob"));
    s.insert(new string("jack"));

    for (auto it : s)
    {
        cout << *it << endl;
    }
}

/**
 * 输出结果如下：
 * bob
 * jack
 * mac
 * 
 * 可以看到，以字符排序的。
 **/