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
    ��ԭ�ַ����д���Ľ����ŵ�һ����̬���ٵĶѿռ��С���������̣���ԭ�ַ��е�aa�滻ΪA��
    ����ԭ�ͣ�char *replace_char(const char *str);
    ��������ֵ:
    ���滻����ַ�����ӡ�����������ͷŶ�̬���ٵ��ڴ�ռ䡣
*/
    char *s = "aa haha heaa ";
    char *p = replace_char(s);
    free(p);
    printf("%s\n", p);
}