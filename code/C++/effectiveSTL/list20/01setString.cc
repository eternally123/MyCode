#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set<string *> s;
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