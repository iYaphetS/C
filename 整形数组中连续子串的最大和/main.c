#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main16()
{
    /*
求数组中连续子串的和最大值
*/
    //int a[] = {1, 2, 8, -21, 78, -23, 109, -32};

    printf("请输入数组长度:");
    int len;
    scanf("%d", &len);

    int a[len];

    for(int i = 0; i < len; i++)
    {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    int maxsum = a[0];
    int index1, index2;//记录最大连续子串的起始与结束下标
    //
    for(int i = 0; i < len; i++)
    {
        sum = 0;//每次求和后要清零
        for(int j = i; j < len; j++)
        {
            sum += a[j];
            if(sum > maxsum)
            {
                maxsum = sum;
                index1 = i;
                index2 = j;
            }
        }

    }

    printf("从%d到%d的子串和最大:%d\n", index1, index2, maxsum);

    return 0;
}