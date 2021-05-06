#include <unordered_set>
#include <iostream>

using namespace std;

int main()
{
    unordered_multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(6);
    cout << "s.size=()" << s.size() << endl;
    cout << "s.max_size()" << s.max_size() << endl;
    cout << "s.bucket_count=()" << s.bucket_count() << endl;
    cout << "s.max_bucket_count=()" << s.max_bucket_count() << endl;
    cout << "s.load_factor=()" << s.load_factor() << endl;
    cout << "s.max_load_factor=()" << s.max_load_factor() << endl;
    cout << "s.count=()" << s.count(6) << endl;
    auto &&range = s.equal_range(6);
    for (auto iter = range.first; iter != range.second; ++iter)
    {
        cout << *iter << "  ";
    }
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