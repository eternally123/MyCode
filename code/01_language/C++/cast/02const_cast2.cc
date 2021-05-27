#include <iostream>

using namespace std;

int main()
{
    char* ps = "helloworld";
    //const char* ps = "helloworld";
    //ps[0] = 'a';
    const_cast<char *>(ps)[0] = 'a';
}
