#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int dif_num(int *a, int len)
{
    int ret = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int main37()
{
    /*
˫ɫ��  6�������1������
    1-33 ѡ6��
    1-16 ѡ1��
�н�����:
    1�� 7
    2�� 6��
    3�� 5��+1��
    4�� 4��+1����5��
    5�� 4�죬3��+1��
    6�� 1������
    �����  û�н�
1���������������һ����ϸù����  һ����
2���ܹ��ж������һ������Ƿ������
3���ܹ��ж������һ���� ���˼��Ƚ�
*/

    //�����������ֲ�ͬ�ж��Ƿ���ÿλ����ͬ
    int num[7] = {0};
    int randnum[7] = {0};

    srand((unsigned)time(NULL));

    for(int i = 0; i < 6; i++)
    {
        randnum[i] = rand() % 33 + 1;
        for(int j = 0; j < i; j++)
        {
            if(randnum[i] == randnum[j])
            {
                i--;
                break;
            }
        }
    }
    randnum[6] = rand() % 16 + 1;

    while(1)
    {
        char buf[100] = {0};
        printf("please input your seven num:");
        fgets(buf, sizeof(buf), stdin);

        if(7 != sscanf(buf, "%d %d %d %d %d %d %d",
                       &num[0],&num[1],&num[2],&num[3],&num[4],&num[5],&num[6])
                || dif_num(num, 6) != 0)//�ж���������Ƿ�Ϸ�
        {
            printf("input error or num repeat\n");
            continue;
        }
        else
            break;
    }

    int count1 = 0, count2 = 0;
    if(num[6] == randnum[6])
    {
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(num[i] == randnum[j])
                    count1++;
            }
        }
        if(count1 == 6)
            printf("һ�Ƚ�\n");
        else if(count1 == 5)
            printf("���Ƚ�\n");
        else if(count1 == 4)
            printf("�ĵȽ�\n");
        else if(count1 == 3)
            printf("��Ƚ�\n");
        else if(count1 == 0)
            printf("���Ƚ�\n");
        else
            printf("лл\n");
    }
    else
    {

        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(num[i] == randnum[j])
                    count2++;
            }
        }
        if(count2 == 6)
            printf("�ĵȽ�\n");
        else if(count2 == 5)
            printf("��Ƚ�\n");
        else
            printf("лл\n");

    }
    return 0;

}