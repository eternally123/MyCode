#include <iostream>
using namespace std;

int ciCharCompare(char c1, char c2)
/**
 * 函数忽略大小比较两个字符
 **/
{
    int lc1 = tolower(static_cast<unsigned char>(c1)); // 转换成小写字母
    int lc2 = tolower(static_cast<unsigned char>(c2));
    cout << "lc1=" << lc1 << endl;
    cout << "lc2=" << lc2 << endl;
    if (lc1 < lc2)
        return -1;
    if (lc1 > lc2)
        return 1;
    return 0;
}

int main()
{
    cout << ciCharCompare('a', 'A') << endl;
    cout << ciCharCompare('a', 'A') << endl;
    cout << ciCharCompare('a', 'b') << endl;
}