#include <stdio.h>
#include <string>

#define DBG_OUTPUT(fmt, args...) printf("CK File[%s:%s(%d)]:" fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##args)
int main()
{
    int i = 10;
    // char *str = "hello world";
    std::string sstr = "hello world";
    DBG_OUTPUT("hello%d", i);
    // DBG_OUTPUT("hello%s", str);
    DBG_OUTPUT("hello%s", sstr.c_str());
}