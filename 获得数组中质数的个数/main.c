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
��ȡ�������������ĸ���
����ԭ�ͣ�int getCountOfPrimer(int arr[],int len,unsigned int *p_count);
�������ܣ���ȡ������arr�������ĸ���
��������:	arr����Ҫ��ɨ�������
    p_count��һ��������ָ�����,����ȡ����������������
��������ֵ��
    �ɹ�����0��
    ����д��󷵻�-1

����������1��������֮��û��������Լ����
Լ�����ֳ�����������a��������b(b��0) ���õ���������������û�����������Ǿ�˵a�ܱ�b��������b������a��

����2����1�ͱ���2�ܹ�����2֮�⣬û�е��������ܹ�����2������2��������
����5����1�ͱ���5�ܹ�����5֮�⣬û�е��������ܹ�����5������5��������
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