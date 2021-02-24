#include <stdio.h>

namespace myname
{
    int var = 42;
}

extern "C" double _ZN6myname3varE;

int main()
{
    printf("%d\n", _ZN6myname3varE);
    return 0;
}

/**
 * g++编译后
 **/
// main.cc:8:19: error: type mismatch with previous external decl of ‘double _ZN6myname3varE’ [-fpermissive]
//  extern "C" double _ZN6myname3varE;
//                    ^
// main.cc:5:9: note: previous external decl of ‘int myname::var’
//      int var = 42;
//          ^
// main.cc:8:19: error: redeclaration of ‘double _ZN6myname3varE’
//  extern "C" double _ZN6myname3varE;
//                    ^
// main.cc:5:9: note: previous declaration ‘int myname::var’
//      int var = 42;