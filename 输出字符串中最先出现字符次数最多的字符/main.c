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
编写一个函数用以获取指定字符串中出现次数最多的字符。
    如果有多个字符出现次数一样，就输出最先出现的那个字符。
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

    printf("出现次数最多的字符是:%c,次数是%d\n", s[index], max);

    return 0;
}