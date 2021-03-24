#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector<vector<int> > vv;
    vector<int> v = {3, 2, 1};
    vv.push_back(v);
    for (auto &it : vv)
        reverse(it.begin(), it.end());

    for (auto &iter : vv)
        for (auto &i : iter)
            cout << i << endl;
}