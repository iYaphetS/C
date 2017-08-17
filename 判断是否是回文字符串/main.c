#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int is_palindrome(const char *str)
{
    int ret = 0;
    int len = strlen(str);
    char *p = str;
    char *q = str + len -1;
    while(p < q)
    {
        if(*p != *q)
            ret = -1;
        p++;
        q--;
    }

    return ret;
}

int main19()
{
    /*
    输入一个字符串，判断其是否是回文字符串。(回文：即正读和反读都一样，如abcba)
    请实现一个函数完成上述功能，并写出相应的测试代码进行验证。

    参考函数原型:int is_palindrome(const char *str);
    函数返回值  :如果是返回0；否则返回非0
*/
    char s[] = "122321";

    int ret = is_palindrome(s);

    printf("%d\n", ret);
    return 0;
}