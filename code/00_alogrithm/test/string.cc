#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

static void split(const string &s, vector<string> &tokens, const string &delimiters = " ")
{
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

int main()
{
    // string s = "123";
    // int val = atoi(s.c_str());
    // cout << val;
    int num = 1;
    int *val = &num;
    *val = (*val) + 1;
}