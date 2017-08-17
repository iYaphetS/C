#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main33()
{
    /*
ͳ���ļ�������ʱ��֮��
�ļ���ÿ�о�Ϊһ��ʱ������01:20:30���뽲���ļ���ÿһ�е�ʱ���ۼ��������ҽ����Ľ��д���ļ�ĩβ
ʾ���ļ� ����������Ӧ��Ϊ02:20:12���ļ�����δ֪��

������ʽ����:
01:00:30
00:20:30
00:59:12
����: ���ǿ����쳣������  �����Ƶ����� ���
*/
    FILE *fp = fopen("t.txt", "r+");

    char buf[1024] = {0};

    int h,m,s;
    int sum_h = 0,sum_m = 0, sum_s = 0;
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        int ret = sscanf(buf, "%d:%d:%d\n", &h, &m, &s);
        if(ret < 3)//����sscanf��ȷƥ��ķ��صĸ������ж�����ĸ�ʽ�Ƿ���ȷ
        {
            fprintf(stderr, "data format err\n");
            break;
        }
        sum_h += h;
        sum_m += m;
        sum_s +=s;
    }

    sum_m += sum_s / 60;
    sum_s %= 60;

    sum_h += sum_m / 60;
    sum_m %= 60;

    fseek(fp, 0, SEEK_END);
    //printf("%d:%02d:%02d\n",sum_h, sum_m, sum_s);
    fprintf(fp, "%d:%02d:%02d\n",sum_h, sum_m, sum_s);

    fclose(fp);

    printf("end\n");


    return 0;
}