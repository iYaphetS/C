#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main39()
{
    /*
求1~n以内所有数中字符(0、1、2、3、4、5、6、7、8、9)分别出现的次数。
    N由键盘输入。

    Input:10
    Output:
1出现2次
0 出现1次
2出现1次
3出现1次
4出现1次
5出现1次
6出现1次
7出现1次
8出现1次
9出现1次
*/
    int num;
    scanf("%d", &num);

    int num_count[10] = {0};

    for(int i = 1; i <= num; i++)
    {
        int j = i;
        while(j)
        {
            num_count[j % 10]++;
            j /= 10;
        }
    }
    for(int j = 0; j < 10; j++)
    {
        printf("%d ", num_count[j]);
    }

    return 0;
}