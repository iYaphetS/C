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
�������������Ӵ��ĺ����ֵ
*/
    //int a[] = {1, 2, 8, -21, 78, -23, 109, -32};

    printf("���������鳤��:");
    int len;
    scanf("%d", &len);

    int a[len];

    for(int i = 0; i < len; i++)
    {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    int maxsum = a[0];
    int index1, index2;//��¼��������Ӵ�����ʼ������±�
    //
    for(int i = 0; i < len; i++)
    {
        sum = 0;//ÿ����ͺ�Ҫ����
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

    printf("��%d��%d���Ӵ������:%d\n", index1, index2, maxsum);

    return 0;
}