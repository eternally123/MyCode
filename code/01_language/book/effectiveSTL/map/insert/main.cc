#include <map>
#include <iostream>

using namespace std;

class A
{
public:
    A() { cout << "A()\n"; }
    A(const A &) { cout << "const A(&)\n"; }
    ~A() { cout << "~A()\n"; }
    int x;
    int y;
};

int main()
{
    map<int, A> m;
    cout << "=====test insert======\n";
    {
        A a;
        a.x = 0;
        a.y = 0;
        cout << "=====insert by []======\n";
        m[1] = a;
        cout << "=====insert by function======\n";
        m.insert(pair<int, A>(2, a));
        cout << "======end======\n";
    }
    cout << "=====test modify======\n";
    {
        A a;
        a.x = 1;
        a.y = 2;
        cout << "=====insert by []======\n";
        m[1] = a;
        cout << "=====insert by function======\n";
        m.insert(pair<int, A>(2, a));
        cout << "=====end======\n";
    }
    cout << m[1].x << m[1].y << endl;
}