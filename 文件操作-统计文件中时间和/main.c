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
统计文件中所有时间之和
文件的每行均为一段时间形如01:20:30；请讲该文件中每一行的时间累加起来并且将最后的结果写到文件末尾
示例文件 最终运算结果应该为02:20:12。文件行数未知。

基本格式如下:
01:00:30
00:20:30
00:59:12
完善: 考虑可能异常的数据  不完善的数据 情况
*/
    FILE *fp = fopen("t.txt", "r+");

    char buf[1024] = {0};

    int h,m,s;
    int sum_h = 0,sum_m = 0, sum_s = 0;
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        int ret = sscanf(buf, "%d:%d:%d\n", &h, &m, &s);
        if(ret < 3)//根据sscanf正确匹配的返回的个数来判断输入的格式是否正确
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