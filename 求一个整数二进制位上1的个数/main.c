#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main4()
{
    /*
��д�����������������(0-255)��bitλ��ֵΪ1��λ��
    ����65,130��133
*/
    int num;
    int count = 0;
    scanf("%d", &num);
    while(num)
    {
        if(num % 2 == 1)
            count++;
        num /= 2;
    }
    printf("count = %d\n", count);

    scanf("%d", &num);
    for(count = 0; num != 0; num >>= 1)
    {
        if(num & 01)
            count++;
        /*
         * ��λ�� &  ȫΪ1��Ϊ1
         * ��λ�� |  ȫΪ0��Ϊ0
         * ��λ�� ~  ��1��0
         * ��λ��� ^ ��ͬΪ0��ͬΪ1(��ͬΪ�٣�0������ͬΪ��)
*/

    }
    printf("count = %d\n", count);

}