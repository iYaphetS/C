#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void format(char *str)//去掉两边的空白字符
{
    char *t = NULL;
    char *p = str;
    char *q = str + strlen(str) - 1;

    while(isspace(*p))
        p++;
    while(isspace(*q))
        q--;
    while(p <= q)
        *t++ = *p++;//将p-q间的字符串拷贝到t指向的空间
    *t = '\0';
    //strncpy(t, p);
    //t[q - p + 1] = '\0'

    return;
}

int main14()
{
    /*
 * 去除一个字符串中两边的可能的空白字符(' ','\t','\n')。
char buf[] = "        			hello heima	\n";
处理之后的字符串是"hello heima"

*/
    //此方法用了一个辅助指针，通过辅助指针p改变原指针s指向的内容
    //如果封装为函数，要传二级指针因为指针的指向发生了改变
    char s[] = "  hello hah heihei zensidou  \n   \r  \t";

    char *p = s;

    p = p + strlen(s) - 1;
    while(isspace(*p))
    {
        *p = '\0';
        p--;
    }
    p = s;
    while(isspace(*p))
        p++;

    printf("(%s)\n", p);//打印的是p指向的内容，指向发生了改变
    return 0;
}