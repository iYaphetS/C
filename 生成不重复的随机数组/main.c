#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


/*生成随机数组
 * 1.第一种方法是边生成边判断
 * --------------------------------
    srand((unsigned)time(NULL));

    for(int i = 0; i < 6; i++)
    {
        randnum[i] = rand() % 33 + 1;
        //随机数字型字符串randnum[i] = rand() % 33 + 1 + '0';
        for(int j = 0; j < i; j++)
        {
            if(randnum[i] == randnum[j])
            {
                i--;
                break;
            }
        }
    }
    ---------------------------------------
    2.第二种方法是先生成，再判断
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

int main()
{
    while(1)
    {
        srand((unsigned)time(NULL));

        for(int i = 0; i < 6; i++)
        {
            randnum[i] = rand() % 33 + 1;
            //随机数字型字符串randnum[i] = rand() % 33 + 1 + '0';
        }
        if(dif_num(randnum, len) == 0)
            break;
    }
}
 --------------------------------------------
*/
int difnumOFstr(char *buf)//
{
    int ret = 0;
    int n = strlen(buf);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(buf[i] == buf[j])//
            {
                ret = 1;//有相同字符
                break;
            }
        }

    }
    return ret;
}
int main38()
{
    /*
计算机产生一个4位不同的随机数，由用户输入判断合法性，4位不重复的仅数字的数，按照下面规则显示结果
A:数字对位置对
B:数字对位置不对
*/

    char a[100] = {0};//存放计算机随机生成数转成的字符串
    srand((unsigned)time(NULL));

    for(int i = 0; i < 4; i++)
    {
        a[i] = rand() % 10 + '0';
        //每产生一个数就与前面的所以数进行比较是否相同
        //相同i--重新生成随机数
        for(int j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                i--;
                break;
            }
        }
    }
    printf("%s\n", a);
    char b[100] = {0};//存放用户输入的数字型字符串
    char p[100] = {0};//记录状态A B,每次检查一个字符都要写入一种状态
    int index = 0;
    while(1)
    {
        memset(b, 0, sizeof(b));//作为缓冲区每次循环都要清空
        memset(p, 0, sizeof(p));
        index = 0;

        printf("plese input 4 numbers(0-9):");
        scanf("%s", b);
        int flag = 0;
        int len = strlen(b);

        //判断数是否合法
        for(int i = 0; i < len; i++)
        {
            if(len != 4 || difnumOFstr(b) == 1 || isdigit(b[i]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("input num error\n");
        }
        else
        {
            for(int i = 0; i < 4; i++)
            {
                if(b[i] == a[i])
                {
                    p[index++] = 'A';
                }
                else
                {
                    for(int j = 0; j < 4; j++)
                    {
                        if(b[i] == a[j])
                            p[index++] = 'B';
                    }
                }
            }

            if(strcmp(p, "AAAA") == 0)
            {
                printf("so good!number is %s\n", b);
                break;
            }
            else if(p[0] == '\0')
            {
                printf("so bad\n");
            }
            else if(p)
            {
                printf("%s\n", p);
            }
        }

    }

    return 0;
}