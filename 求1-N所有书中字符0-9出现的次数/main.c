#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main39()
{
    /*
��1~n�������������ַ�(0��1��2��3��4��5��6��7��8��9)�ֱ���ֵĴ�����
    N�ɼ������롣

    Input:10
    Output:
1����2��
0 ����1��
2����1��
3����1��
4����1��
5����1��
6����1��
7����1��
8����1��
9����1��
*/
    int num;
    scanf("%d", &num);

    int num_count[10] = {0};

    for(int i = 1; i <= num; i++)
    {
        int j = i;
        while(j)
        {
            num_count[j % 10]++;
            j /= 10;
        }
    }
    for(int j = 0; j < 10; j++)
    {
        printf("%d ", num_count[j]);
    }

    return 0;
}