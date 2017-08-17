#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


char *replace_char(const char *str)
{
    char *p = calloc(1, strlen(str));
    if(p == NULL)
    {
        return NULL;
    }

    //p = str;
    int index = 0;
    while(*str)
    {
        if(*str == 'a' && *(str + 1) == 'a')
        {
            p[index++] = 'A';
            str++;
            //p[index++] = *str;
        }
        else
            p[index++] = *str;
        str++;
    }

    return p;
}

int main24()
{
    /*
    将原字符串中处理的结果存放到一个动态开辟的堆空间中。（处理过程：将原字符中的aa替换为A）
    函数原型：char *replace_char(const char *str);
    函数返回值:
    将替换后的字符串打印出来，并且释放动态开辟的内存空间。
*/
    char *s = "aa haha heaa ";
    char *p = replace_char(s);
    free(p);
    printf("%s\n", p);
}