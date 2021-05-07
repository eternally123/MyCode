#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        tbl.resize(n);
        if (n == 0)
            return 1;
        double result;
        if (n > 0)
        {
            result = Pow(x, n);
        }
        if (n < 0)
        {
            result = Pow(x, -n);
            result = 1 / result;
        }
        return result;
    }

    double Pow(double x, int n)
    { //n>=1
        int index = 1;
        double result = x;
        for (; index < n; index = index * 2)
        {
            tbl[index] = result;
            result = result * result;
        }
        result = 1;
        while (n > 0)
        {
            if (tbl[n] != 0)
                return result * tbl[n];
            int tmp = n;
            while (tbl[--tmp] == 0)
            {
            }
            result = result * tbl[tmp];
            n = n - tmp;
        }
        return result;
    }

private:
    vector<double> tbl;
};
int main()
{
    Solution s;
    cout << s.myPow(2.00000, 10) << endl;
    map<int, int> m;
    int value = 10;
    auto iter = m.find(value);
    if (iter != m.end())
    {
        cout << iter->second;
    }
}