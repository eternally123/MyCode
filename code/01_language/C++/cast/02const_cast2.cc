#include <iostream>

using namespace std;

int main()
{
    const char ps[] = "helloworld";
    // ps[0] = 'a';
    const_cast<char *>(ps)[0] = 'a';
}