#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void s_reverse(char *s)
{
    char *p = s;
    char *q = s + strlen(s) - 1;
    while(p < q)
    {
        char temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
    /*
    int len = strlen(s);
    for(int i = 0, int j = len - 1; i < j;i++, j--)
        char temp = s[i], s[i] = s[j], s[j] = temp;
*/
}


//itoa实现方法
//可以用sprintf(s, "%d", num);一步实现
/*
 * 进制转换
 * 1.十进制转八进制数字符串----sprintf(buf, "%o", num);---atoi(buf)
 * 2.十进制转十六进制字符串--sprintf(buf, "%x", num);----atoi(buf)
 * 3.十进制转二进制----
 * int i = 0;
 * while(num)
 * {
 *      snum += (num % 2) * pow(10, i);
 *      num /= 2;
 * }
*/
void myitoa(int num, char *s)
{
    //char s[100] = {0};
    int sign, i;
    if((sign = num) < 0)
        num = -num;
    i = 0;
    do
    {
        s[i++] = num % 10 + '0';
    }while(num /= 10);
    /*
    while(num)
    {
        s[i++] = num % 10 + '0';
        num /= 10;
    }
    */
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    s_reverse(s);
    return s;
}

int main26()
{
    /*
itoa实现
*/
    printf("please input a number:");
    int num;
    scanf("%d", &num);
    char *buf = NULL;
    //char *s = myitoa(num);
    myitoa(num, buf);
    printf("%s\n", buf);//

    return 0;
    //---------------------------------
}