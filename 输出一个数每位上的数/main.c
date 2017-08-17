
#include <stdio.h>

int main1(void)
{
    /*
课间练习编程
根据每个位上的权值使用5则运算求出1234每个位上的数字

运行结果如下：
千位上值为1
百位上值为2
十位上值为3
个位上值为4
*/
    int num = 12345;

    int a = num % 10;
    int b = num / 10 % 10;
    int c = num /100 % 10;
    int d = num /1000 % 10;
    int e = num /10000;

    printf("%d %d %d %d %d\n", a, b, c, d, e);
    return 0;
}