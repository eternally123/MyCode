#include <iostream>

using namespace std;

class People
{
public:
    void print()
    {
        cout << num << endl;
    }
    int num = 10;
};

People &func()
{
    People p;
    return p;
}

int main()
{
    People p = func();
}