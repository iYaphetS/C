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
    完成UNIX时间戳到北京时间(东八区 +8时区)日期格式的转化。
    UNIX时间戳表示从1970年1月1日0:0:0到某个被测时间点的秒数。
    1489937291  表示此时到1970年1月1日0:0:0已经经历了 1489937291秒
    此刻是北京时间2017/3/19 23:28:11

    489937291对应的北京时间1985/7/11 21:41:31
*/
    int y, m, d;
    int hour,min,sec;
    int timestamp = 0;
    printf("please input timestamp:");
    scanf("%d", &timestamp);
    clock_t begin = clock();//记录开始的时间（毫秒）

    //东八区 + 8个小时
    timestamp += 3600 * 8;

    //用一个零时变量接剩余的总时间
    int temp = timestamp;
    for(y = 1970; ; y++)
    {
        //润年比平年多一天，根据是不是闰年来考虑加不加这一天总秒数
        temp -= isleapyear(y) * oneday_second + leapyear_second;
        if(temp > 0)
            timestamp = temp;
        else
            break;
    }
    //如果不用零时变量temp，要跳出循环timetamp必须减到负数，
    //那么想得到剩余的总月数，还得加上一年的时间，还得判断加上的这年是否是闰年

    //剩余不足一年的总时间
    temp = timestamp;
    for(m = 1; m < 13; m++)
    {
        temp -= getdaysofmon(y,m) * oneday_second;
        if(temp > 0)
            timestamp = temp;
        else
            break;
    }

    //剩余不足一个月的总时间
    temp = timestamp;
    for(d = 1; d < getdaysofmon(y,m); d++)
    {
        temp -= oneday_second;
        if(temp > 0)
            timestamp = temp;
        else
            break;
    }

    //得到不足一天的时分秒（就像求1234各个位上的值是一个道理，只不过时间是60进制的）
    temp = timestamp;
    sec = temp % 60;
    min = temp /60 % 60;
    hour = temp / 60 /60;

    printf("%4d,%02d,%02d %02d:%02d:%02d\n", y, m, d, hour, min, sec);

    clock_t end = clock();//记录结束时间（毫秒）CLOCKS_PER_SEC == 1000
    printf("%d\n", (float)((end - begin) / CLOCKS_PER_SEC));
    return 0;
}