#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//�ж��Ƿ�Ϊƽ�꣨���꣩
//���꣺�ܱ�4���������ǲ��ܱ�100����  ��   �ܱ�400����
int isLeapYear(int y)
{
    int ret;
    if(y % 4 == 0 && y % 100 || y % 400 == 0)
        ret = 1;
    else
        ret = 0;

    return ret;
}

//ĳ��ĳ��ĳ�վ���1.1�ж�����
int Numbers(int y, int m, int d)
{
    /*
    if(m < 1 || m > 12)
    {
        printf("mon num error\n");
        exit(-1);
    }
    int day[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31}};
    if(isLeapYear(y))
    {
        if(d > 29 || d < 1)
        {
            printf("day num error\n")
            exit(-1);
        }

        for(int i = 0; i < m; i++)
            count += day[1][i];
    }
    else
    {
        if(d > 28 || d < 1)
        {
            printf("day num error\n")
            exit(-1);
        }
        for(int j = 0; j < m; j++)
            count += day[0][j];
    }
    count += d;

*/
    int count = 0;
    if(m <= 0 || m > 12)
    {
        printf("error number of mon\n");
        exit(-1);
    }
    while(m)
    {
        switch(m)
        {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            if(d <= 0 || d > 31)
            {
                printf("error number of day\n");
                exit(-1);
            }
            count += 31;
            break;
        case 4:case 6:case 9:case 11:
            if(d <= 0 || d > 30)
            {
                printf("error number of day\n");
                exit(-1);
            }
            count += 30;
            break;
        case 2:
            if(isLeapYear(y))
            {
                if(d <= 0 || d > 29)
                {
                    printf("error number of day\n");
                    exit(-1);
                }
            }
            else
            {
                if(d <= 0 || d > 28)
                {
                    printf("error number of day\n");
                    exit(-1);
                }
            }
            count += 28 + isLeapYear(y);
            break;
        default:
            break;
        }
        m--;
    }
    count += d;
    return count;
}

//ĳ��ĳ��ĳ�յ�ĳ��ĳ��ĳ���ж�����
int getNumbers(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int sum = 0;
    for(int y = y1; y < y2; y++)
        sum += 365 + isLeapYear(y);

    return sum + Numbers(y2, m2, d2) - Numbers(y1, m1, d1);

}

int main11()
{

    /*
 * д1������ ���ҵ��� ������н����
    int getNumbers(int y1,int m1,int d1,int y2,int m2,int d2);
    ��������: ��ȡ��y1��m1��d1�յ�y2��m2��d2��֮���ж����죿
    ����ֵ:   ������������֮�������������
*/
    int y1,m1,d1,y2,m2,d2;
    printf("��������ʼ������:");
    scanf("%d%d%d", &y1, &m1, &d1);
    printf("�������ֹ������:");
    scanf("%d%d%d", &y2, &m2, &d2);

    int days = getNumbers(y1, m1, d1, y2, m2, d2);

    printf("�м������%d��\n", days);

    return 0;
}