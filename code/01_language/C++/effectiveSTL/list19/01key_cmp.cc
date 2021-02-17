#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;
    cout << m.key_comp()(1, 2) << endl;
    cout << m.key_comp()(1, 1) << endl;
    cout << m.key_comp()(1, 0) << endl;
}

/**
 * 利用的是operator<来做的，所以返回值为1 0 0
 **/