#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int isPrimer(int num)
{
    int ret = 0;
    if(num < 2)
        ret = 1;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

int getCountOfPrimer(int arr[],int len,unsigned int *p_count)
{
    if(arr == NULL || p_count == NULL || len < 0)
    {
        return -1;
    }
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(isPrimer(arr[i]) == 0)
            count++;
    }
    *p_count = count;
}

int main32()
{
    /*
获取到数组中质数的个数
函数原型：int getCountOfPrimer(int arr[],int len,unsigned int *p_count);
函数功能：获取到数组arr中质数的个数
函数参数:	arr是需要被扫描的数组
    p_count是一个传出的指针参数,将获取到的质数个数传出
函数返回值：
    成功返回0；
    如果有错误返回-1

质数：除了1和数本身之外没有其他的约数。
约数：又称因数。整数a除以整数b(b≠0) 除得的商正好是整数而没有余数，我们就说a能被b整除，或b能整除a。

质数2除了1和本身2能够整除2之外，没有第三个数能够整除2，所以2是质数。
质数5除了1和本身5能够整除5之外，没有第三个数能够整除5，所以5是质数。
*/
    int arr[10] = {1,2,3,4,5,6,7,8,9,13};

    int len = sizeof(arr) / sizeof(arr[0]);
    int ret = 0;
    int count = 0;
    //   ret = isPrimer(13);
    //  printf("%d\n", ret);
    ret = getCountOfPrimer(arr, len, &count);

    printf("%d\n", count);

    return 0;
}