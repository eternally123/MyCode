#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str = "hello world!";
    int index = str.find_first_not_of("hll", 0);
    cout << index << endl;
    return 0;
}