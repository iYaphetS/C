#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int myatoi(char *s)
{
    int i = 0, sign;
    int num = 0;

    while(isspace(s[i]))
        i++;

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '-' || s[i] == '+')
        i++;


    while(isdigit(s[i]))
    {
        num = num*10 + (s[i] - '0');
        i++;
    }
    /*myatoi复杂算法

int mystrlen(char *s)
{
    int len = 0;
    while (s[len])
        len++;

    return len;
}

int base(int n)
{
    int base = 1;
    int i;
    for (i = 0; i < n; i++)
        base *= 10;

    return base;

}
int myatoi(char *s)
{
    int value = 0;
    int len = mystrlen(s);
    int i;
    if(isspace(*s))
        s++;

    //if (s[0] = '-')
    if ('-' == s[0])
    {
        for (i = 1; i < len ; i++)
        {
            value -= base(len - i - 2) * (s[i] - '0');
        }
    }
    else
    {
        for (i = 0; i < len; i++)
        {

            value += base(len - i - 1) * (s[i] - '0');
            //value += pow(10, len - i -1) * (s[i] - '0');
        }
    }

    return value;
}
    */
    if(sign < 0)
        num = -num;
    return num;
}

int main25()
{
    /*
atoi实现
*/
    char buf[128] = " 1234";//"   234", "+123", "  -122"

    int ret = myatoi(buf);
    printf("%d\n", ret);
    return 0;
}