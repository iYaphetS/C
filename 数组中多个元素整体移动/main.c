#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//��һ�������������Ӵ��������ַ������Ӵ������������ƶ�k��λ��
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
��n�������������ǰ��ĸ�������������ƶ�k��λ�ã����k�����Ƶ���ǰ�ߵ�k��λ��
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