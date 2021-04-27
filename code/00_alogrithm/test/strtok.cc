#include <string.h>
#include <stdio.h>

int main()
{
    char str[80] = "This is-awww.runoob.com-awebsite";
    printf("%p\n", str);
    const char s[3] = "-a";
    char *token;

    /* 获取第一个子字符串 */
    token = strtok(str, s);

    /* 继续获取其他的子字符串 */
    while (token != NULL)
    {
        printf("%p,%s\n", token, token);

        token = strtok(NULL, s);
    }

    printf("%d,%d", str[7], str[8]);
    return (0);
}