
#include <stdio.h>

int main()
{

    /*
求数组中最大值和第二大的值
*/
    int a[10] = {1, 2, 3, 4, 12, 32, 42, 18, 10, 6};

    int max;
    int smax;
    if(a[0] > a[1])
    {
        max = a[0];
        smax = a[1];
    }else
    {
        max = a[1];
        smax = a[0];
    }
    for(int i = 0; i < 10; i++)
    {
        if(a[i] > max)
        {
            smax = max;
            max = a[i];
        }else if(a[i] <= max && a[i] > smax)
            smax = a[i];
    }
    printf("smax = %d max = %d\n", smax, max);
    return 0;
}