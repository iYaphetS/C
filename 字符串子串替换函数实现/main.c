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
ʵ��һ��lite����ַ����滻����
���¹��� -C/C++: char *strreplace(char *str, const char *sub, const char *rep)
����������Ҫ������:
����strΪԭ�ַ�����subΪ�����滻���Ӵ���Ϊ�����, �ٶ��ַ���sub��rep����һ��
ֱ�Ӷ�ԭ�ַ���str�����޸Ĳ�����, ����ʹ��malloc/new�����µ��ڴ�ռ�
����ʹ���κο⺯��/API, ������������strlen, strstr, strcpy, ����ʹ�����ƹ���, ������
ʵ��
*/
    char p[100] = "abc key KEsss";

    char *str = strreplace(p, "key", "KEY");

    printf("%s\n", str);

}