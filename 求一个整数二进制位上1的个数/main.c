#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main4()
{
    /*
编写代码求出给定的整数(0-255)中bit位上值为1的位数
    比如65,130，133
*/
    int num;
    int count = 0;
    scanf("%d", &num);
    while(num)
    {
        if(num % 2 == 1)
            count++;
        num /= 2;
    }
    printf("count = %d\n", count);

    scanf("%d", &num);
    for(count = 0; num != 0; num >>= 1)
    {
        if(num & 01)
            count++;
        /*
         * 按位与 &  全为1才为1
         * 按位或 |  全为0才为0
         * 按位非 ~  非1即0
         * 按位异或 ^ 相同为0不同为1(相同为假（0），不同为真)
*/

    }
    printf("count = %d\n", count);

}