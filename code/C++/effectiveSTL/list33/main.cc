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