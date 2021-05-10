#include <vector>
#include <iostream>

using namespace std;

class Obj
{
public:
    Obj() { cout << "Obj()\n"; }
    Obj(const Obj &obj) { cout << "Obj(const&)\n"; }
    Obj(Obj &&obj) noexcept { cout << "Obj(&&)\n"; }
};

int main()
{
    vector<Obj> v;
    v.reserve(20);
    for (int i = 0; i < 1; i++)
    {
        v.emplace_back();
    }
}