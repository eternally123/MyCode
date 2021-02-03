#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class Widget
{
public:
    Widget(int n) : num(n) {}
    int get() { return num; }
    int num;
};

bool judge(shared_ptr<Widget> &p)
{
    if (p->get() < 5)
        return true;
    else
        return false;
}

int main()
{
    vector<shared_ptr<Widget>> v;
    v.push_back(make_shared<Widget>(1));
    v.push_back(make_shared<Widget>(7));
    v.push_back(make_shared<Widget>(8));
    v.push_back(make_shared<Widget>(2));
    v.push_back(make_shared<Widget>(4));
    v.push_back(make_shared<Widget>(3));
    v.push_back(make_shared<Widget>(5));
    v.push_back(make_shared<Widget>(9));
    v.push_back(make_shared<Widget>(6));

    for (auto &it : v)
    {
        cout << it->get() << " ";
    }
    cout << endl;
    v.erase(remove_if(v.begin(), v.end(), judge), v.end());

    for (auto &it : v)
    {
        cout << it->get() << " ";
    }
    cout << endl;
}

/**
 * 对于指针类数据使用remove的时候一定要注意，可能出现资源泄露。
 * 因为remove结束后，后面的不一定是多于的数据。而是不可预测的数据。
 * 
 * 解决方式是：
 * ①用智能指针
 * ②先遍历，筛选出不符合的标记，然后释放资源，然后在用remove erase识别标记进行删除。
 **/