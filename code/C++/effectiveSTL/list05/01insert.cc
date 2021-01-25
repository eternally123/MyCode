#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> m;
    vector<int> n;
    for (int i = 0; i < 10; i++)
    {
        m.push_back(i);
        n.push_back(i);
    }
    n.insert(n.begin(), m.begin(), m.end());
    for (auto &it : n)
        cout << it << "\t";
    cout << endl;
}