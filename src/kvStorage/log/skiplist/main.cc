#include "skiplist.hh"

#include <iostream>

int main()
{
    SkipList<int, int> s(10);
    s.insert(10, 10);
    std::cout << s.search(10) << std::endl;
}