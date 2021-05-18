#include "skiplist.hh"

#include <iostream>

int main()
{
    SkipList<int, int> sl(32);
    for (int i = 0; i < 10; i++)
    {
        sl.insert_element(i, i);
    }
    std::cout << sl.search_element(888) << std::endl;
    std::cout << sl.size() << std::endl;
    sl.display_list();
}