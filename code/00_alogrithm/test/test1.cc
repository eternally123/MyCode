#include <vector>
#include <iostream>

using namespace std;
class People
{
public:
    People()
    {
        cout << "construct" << endl;
    }
    People(const People &p)
    {
        cout << "copy construct" << endl;
    }
};

int main()
{
    vector<People> v;
    v.resize(10);
    cout << "==========" << endl;
    v.reserve(20);
}