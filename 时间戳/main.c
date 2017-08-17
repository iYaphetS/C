#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

const int oneday_second = 24 * 60 * 60;
const int leapyear_second = 365 * 24 * 60 * 60;

int isleapyear(int y)
{
    int ret = 0;
    if(y % 4 == 0 && y % 100 || y % 400 == 0)
        ret = 1;
    return ret;
}

int getdaysofmon(int y, int m)
{
    int monday[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
                         {31,39,31,30,31,30,31,31,30,31,30,31}};
    return monday[isleapyear(y)][m];
}

int main30()
{
    /*
    ���UNIXʱ���������ʱ��(������ +8ʱ��)���ڸ�ʽ��ת����
    UNIXʱ�����ʾ��1970��1��1��0:0:0��ĳ������ʱ����������
    1489937291  ��ʾ��ʱ��1970��1��1��0:0:0�Ѿ������� 1489937291��
    �˿��Ǳ���ʱ��2017/3/19 23:28:11

    489937291��Ӧ�ı���ʱ��1985/7/11 21:41:31
*/
    int y, m, d;
    int hour,min,sec;
    int timestamp = 0;
    printf("please input timestamp:");
    scanf("%d", &timestamp);
    clock_t begin = clock();//��¼��ʼ��ʱ�䣨���룩

    //������ + 8��Сʱ
    timestamp += 3600 * 8;

    //��һ����ʱ������ʣ�����ʱ��
    int temp = timestamp;
    for(y = 1970; ; y++)
    {
        //�����ƽ���һ�죬�����ǲ������������ǼӲ�����һ��������
        temp -= isleapyear(y) * oneday_second + leapyear_second;
        if(temp > 0)
            timestamp = temp;
        else
            break;
    }
    //���������ʱ����temp��Ҫ����ѭ��timetamp�������������
    //��ô��õ�ʣ��������������ü���һ���ʱ�䣬�����жϼ��ϵ������Ƿ�������

    //ʣ�಻��һ�����ʱ��
    temp = timestamp;
    for(m = 1; m < 13; m++)
    {
        temp -= getdaysofmon(y,m) * oneday_second;
        if(temp > 0)
            timestamp = temp;
        else
            break;
    }

    //ʣ�಻��һ���µ���ʱ��
    temp = timestamp;
    for(d = 1; d < getdaysofmon(y,m); d++)
    {
        temp -= oneday_second;
        if(temp > 0)
            timestamp = temp;
        else
            break;
    }

    //�õ�����һ���ʱ���루������1234����λ�ϵ�ֵ��һ������ֻ����ʱ����60���Ƶģ�
    temp = timestamp;
    sec = temp % 60;
    min = temp /60 % 60;
    hour = temp / 60 /60;

    printf("%4d,%02d,%02d %02d:%02d:%02d\n", y, m, d, hour, min, sec);

    clock_t end = clock();//��¼����ʱ�䣨���룩CLOCKS_PER_SEC == 1000
    printf("%d\n", (float)((end - begin) / CLOCKS_PER_SEC));
    return 0;
}