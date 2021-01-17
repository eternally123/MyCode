#include "Directory.hh"

Directory::Directory()
{
    int disks = tfs.numDisks();
    cout << disks << endl;
}

Directory d;