#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main17()
{
    /*
��дһ���������Ի�ȡָ���ַ����г��ִ��������ַ���
    ����ж���ַ����ִ���һ������������ȳ��ֵ��Ǹ��ַ���
*/
    char s[] = "sdddddddddddddddddd222222ajjjjjjseshahsha";
    int len = strlen(s);
    int count[len];
    int index = 0;
    for(int i = 0; i < len; i++)
    {
        count[i] = 0;
    }

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(s[i] == s[j])
                count[i]++;
        }
    }

    int max = count[0];

    for(int i = 0; i < len; i++)
    {
        if(max < count[i])
        {
            max = count[i];
            index = i;
        }

    }

    printf("���ִ��������ַ���:%c,������%d\n", s[index], max);

    return 0;
}