#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//将一个定长的数组子串（或者字符串的子串）整体向右移动k个位置
void move_right(int *arr, int n, int k)//
{
    for(int i = 0; i < k; i++)
    {
        int temp = arr[n - 1];
        for(int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

int main22()
{
    /*
有n个整数，编程序将前面的各个数依次向后移动k个位置，最后k个数移到最前边的k个位置
*/
    int arr[] = {2, 3, 5, 8, 4, 9, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    int k = 2;
    move_right(arr, len, k);

    for(int i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}