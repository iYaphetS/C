#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main34()
{
    /*
找出文件中身高/体重比最小的人，行数未知。
文件格式:

name=xxx1,high=xxxx,weight=xxxxx
name=xxx2,high=xxxx,weight=xxxxx
name=xxx3,high=xxxx,weight=xxxxx
*/
    FILE *fp = fopen("s.txt", "r");

    char buf[1024] = {0};
    char name[64] = {0};
    char high[64] = {0};
    char weight[64] = {0};
    char fatman[64];

    double min_rate = 100;
    double rate = 0;
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        sscanf(buf, "%*[^=]=%[^,]%*[^=]=%[^,]%*[^=]=%[^\n]", name,high,weight);
        rate = atof(high) / atof(weight);
        if(rate < min_rate)
        {
            min_rate = rate;
            strcpy(fatman, name);
        }
    }
    printf("%s\n", fatman);
    fclose(fp);

    return 0;
}