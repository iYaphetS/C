#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

char *mystrstr(const char *str, const char *sub)
{
    for(int i = 0; str[i]; i++)
    {
        int j = 0;
        int temp = i;
        while(str[i++] == sub[j++])
        {
            if(sub[i] == '\0')
                return str + temp;
        }
        i = temp;
    }
    return NULL;
}

char *strreplace(char *str, const char *sub, const char *rep)
{

    char *p = mystrstr(str, sub);

    while(*rep)
    {
        *p++ = *rep++;
    }
    return str;
}

int main40()
{
/*
实现一个lite版的字符串替换函数
创新工场 -C/C++: char *strreplace(char *str, const char *sub, const char *rep)
限制条件和要求如下:
其中str为原字符串，sub为待被替换的子串。为简单起见, 假定字符串sub和rep长度一样
直接对原字符串str进行修改并返回, 不得使用malloc/new开辟新的内存空间
不得使用任何库函数/API, 包括但不限于strlen, strstr, strcpy, 如需使用类似功能, 请自行
实现
*/
    char p[100] = "abc key KEsss";

    char *str = strreplace(p, "key", "KEY");

    printf("%s\n", str);

}