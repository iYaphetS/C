#include <stdio.h>

int main()
{
    /*
求数组去掉最大值和最小值的平均值
*/
    int a[10] = {45, 67, 100, 90, 80, 20, 89, 66, 98, 93};
    int max = a[0];
    int min = a[0];
    int avg, sum;
    for(int i = 0; i < 10; i++)
    {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];

        sum += a[i];
    }
    avg = (sum - max -min) / 8;
    printf("%d\n", avg);
    return 0;
}