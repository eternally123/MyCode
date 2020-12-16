#include <iostream>
using namespace std;

class AbsInt
{
public:
    int operator()(int val)
    {
        return val < 0 ? -val : val;
    }
};

int main()
{
    AbsInt abs;
    int num = abs(-10);
    cout << num << endl;
    // int j = {1.2}; // 不能通过编译
}