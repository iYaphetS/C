#include <stdio.h>

int main()
{
    /*
用随机数初始化一个二维数组 并且打印这个二维数组.
*/

    srand((unsigned)time(NULL));//include <time.h>
    int i,j;
    int arr[3][5] = {0};
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            arr[i][j] = rand() % 100 + 1;
            printf("arr[%d][%d] = %d ", i, j, arr[i][j]);
        }
    }
    return 0;
}