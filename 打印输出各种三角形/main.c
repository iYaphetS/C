#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    //倒三角第二次循环是从i开始的到n（或者从0开始到n-i）
    //正三角第二次循环是从1开始的到i
    /*
......
.....
....
...
..
.
*/
    int i,j,k;
    for(i = 1; i < 10; i++)
    {
        for(j = i; j < 10; j++)
        {
            printf("%d*%d=%d\t", i, j, i*j);
        }

        printf("\n");

    }

    /*
.
..
...
....
.....
......
*/
    for(i = 1; i < 10; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d*%d=%d\t", i, j, i*j);
        }
        printf("\n");
    }
    /*
     .
    ..
   ...
  ....
 .....
......
*/
    for(i = 1; i < 10; i++)
    {
        for(k = i; k < 9; k++)
        {
            printf("\t");
        }
        for(j = 1; j <= i; j++)
        {
            printf("%d*%d=%d\t", i, j, i*j);
        }
        printf("\n");
    }
    /*
.....
 ....
  ...
   ..
    .
*/
    for(i = 1; i < 10; i++)
    {
        for(k = 1; k < i; k++)
        {
            printf("\t");
        }
        for(j = i; j < 10; j++)
        {
            printf("%d*%d=%d\t", i, j, i*j);
        }

        printf("\n");
    }
}
int main1()
{
    /*类似的杨辉三角
1       2       3       4       5       6       7       8       9       10
3       5       7       9       11      13      15      17      19
8       12      16      20      24      28      32      36
20      28      36      44      52      60      68
48      64      80      96      112     128
112     144     176     208     240
256     320     384     448
576     704     832
1280    1536
2816
*/
    int n;
    scanf("%d", &n);
    int a[n][n];

    for(int j = 0; j < n; j++)
    {
        a[0][j] = j + 1;
        printf("%d\t", a[0][j]);
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j + 1];
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}