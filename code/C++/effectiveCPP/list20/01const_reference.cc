#include <iostream>

using namespace std;
class People
{
public:
    virtual void say() const
    {
        cout << "people say\n";
    }
};

class Men : public People
{
public:
    virtual void say() const
    {
        cout << "Men say\n";
    }
};

void func(const People &p)
{
    p.say();
}

int main()
{
    Men m;
    func(m);
}