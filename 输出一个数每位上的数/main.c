
#include <stdio.h>

int main1(void)
{
    /*
�μ���ϰ���
����ÿ��λ�ϵ�Ȩֵʹ��5���������1234ÿ��λ�ϵ�����

���н�����£�
ǧλ��ֵΪ1
��λ��ֵΪ2
ʮλ��ֵΪ3
��λ��ֵΪ4
*/
    int num = 12345;

    int a = num % 10;
    int b = num / 10 % 10;
    int c = num /100 % 10;
    int d = num /1000 % 10;
    int e = num /10000;

    printf("%d %d %d %d %d\n", a, b, c, d, e);
    return 0;
}