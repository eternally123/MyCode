#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(int a, int b)
{
    return a < b;
}

int main()
{
    vector<int> v;
    for (int i = 1; i <= 10; i++)
        v.push_back(i);

    cout << binary_search(v.begin(), v.end(), 5, Comp) << endl;  // bool true
    cout << binary_search(v.begin(), v.end(), 20, Comp) << endl; // bool false
}

/**
 * binary查找某元素是否在集合中，返回true或false
 * 
 * bool binary_search (ForwardIterator first, ForwardIterator last, const T& value)
 * bool binary_search (ForwardIterator first, ForwardIterator last, const T& value, Compare comp)
 * 查找是否在[first,last)中存在iterator i,满足 
 * !(*i<value) && !(value<*i)  或者 comp(*i,value)==false && comp(value,*i)==false 
 * 存在则返回true,否则返回false. 
 **/