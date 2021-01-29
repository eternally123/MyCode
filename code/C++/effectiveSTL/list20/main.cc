#include <iostream>
#include <set>
#include <string>
using namespace std;

struct StringPtrLess
{
    bool operator()(const string *ps1, const string *ps2) const
    {
        return *ps1 < *ps2;
    }
};

int main()
{
    set<string *, StringPtrLess> s;
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
 * mac
 * bob
 * jack
 * 
 * 可以看到，以指针地址排序的。
 **/