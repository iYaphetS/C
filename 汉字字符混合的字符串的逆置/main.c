#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main12()
{
    /*
 * 编写函数完成逆置GBK(UTF-8编码)的汉字字符串的功能。
*/
    char s[] = "haue艾尔阿姐卡克123ABC";

    int len = strlen(s);
    //整体逆置
    for(int i = 0; i < len /2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;

    }
    //汉字单独逆置
    for(int i = 0; i < len; i++)
        //为什么把字符跳格数分两步呢，因为字符串中非中文的字符是一个字节，当不是中文字符时，只需要跳过一个字节
    {
        if(s[i] < 0)//判断是否是中文字符的依据，对应的值是负数
        {
            char temp = s[i];
            s[i] = s[i + 1];
            //s[i] = s[i + 2];//utf-8
            s[i + 1] = temp;
            //s[i + 2] = temp;
            i += 1;
            //i += 2;
        }
    }

    printf("%s", s);
    return 0;
}