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
双色球  6个红球和1个蓝球
    1-33 选6个
    1-16 选1个
中奖规则:
    1等 7
    2等 6红
    3等 5红+1蓝
    4等 4红+1蓝，5红
    5等 4红，3红+1蓝
    6等 1个蓝球
    其余的  没有奖
1、利用随机数产生一组符合该规则的  一组编号
2、能够判断输入的一组编码是否负责规则
3、能够判断输入的一组编号 中了几等奖
*/

    //这里用了两种不同判断是否是每位都不同
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
                || dif_num(num, 6) != 0)//判断输入的数是否合法
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
            printf("一等奖\n");
        else if(count1 == 5)
            printf("三等奖\n");
        else if(count1 == 4)
            printf("四等奖\n");
        else if(count1 == 3)
            printf("五等奖\n");
        else if(count1 == 0)
            printf("六等奖\n");
        else
            printf("谢谢\n");
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
            printf("四等奖\n");
        else if(count2 == 5)
            printf("五等奖\n");
        else
            printf("谢谢\n");

    }
    return 0;

}