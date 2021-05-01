#include "filesystem.hh"

#include <iostream>
using namespace std;

extern FileSystem tfs;

class Directory
{
public:
    Directory();
    void print()
    {
        cout << "direct" << endl;
    }
};