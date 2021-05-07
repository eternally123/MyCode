#include <iostream>
#include <set>

class Obj
{
public:
    Obj(int v) : val(v), val2(0) {}
    Obj(int v, int p) : val(v), val2(p) {}
    int val = 0;
    int val2 = 0;
};

struct ObjComp
{
    bool operator()(const Obj &b1, const Obj &b2)
    {
        return b1.val < b2.val;
    }
};

int main()
{
    set<Obj> s;
}