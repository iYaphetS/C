#include <stdio.h>


int isOddNumber(unsigned num)//判断是否为奇数
{
    int ret;
    if(num % 2)
        ret = 0;
    else
        ret = 1;

    return ret;
}

int main10()
{
    /*
奇数。
    函数原型 int isOddNumber(unsigned int number);
    函数功能 判断参数number是否是奇数 奇数判断依据是是否能够被2整除。
    函数返回值 如果是奇数返回0;如果不是奇数返回1
*/
    unsigned num;
    scanf("%d", &num);

    int ret = isOddNumber(num);
    if(ret == 0)
        printf("奇数\n");
    else
        printf("偶数\n");

}