#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    unordered_map<int, int> m;
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(2, 2));
    m.insert(pair<int, int>(3, 3));
    m.insert(pair<int, int>(4, 4));
    for (auto &&iter : m)
    {
        cout << typeid(iter).name() << endl;
    }
    int n;
}

/**
s.size=()8
s.max_size()1152921504606846975
s.bucket_count=()11
s.max_bucket_count=()1152921504606846975
s.load_factor=()0.727273
s.max_load_factor=()1
s.count=()3
6  6  6  
 **/