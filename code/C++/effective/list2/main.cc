#include <iostream>
using namespace std;

#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))

template <typename T>
inline int callWithMax(const T &a, const T &b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 5;
    int b = 0;
    cout << "inline function:" << callWithMax(++a, b) << endl;      //6
    cout << "define:" << CALL_WITH_MAX(++a, b) << endl;             //8
    cout << "inline function:" << callWithMax(++a, b + 10) << endl; //10
    cout << "define:" << CALL_WITH_MAX(++a, b + 10) << endl;        //10
}

// 用inline function代替define是很好的选择