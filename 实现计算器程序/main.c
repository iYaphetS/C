#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int add(int num1, int num2)
{
    return num1 + num2;

}
int sub(int num1, int num2)
{
    return num1 - num2;
}
int mux(int num1, int num2)
{
    return num1 * num2;

}
int dive(int num1, int num2)
{
    if(num2 == 0)
    {
        printf("num2 can't zero\n");
    }else
        return num1 / num2;
}

int main21()
{
    /*
计算器程序。
    设计一个计算器，可以进行加、减、乘、除运算，类型全部都是int即可
要求从键盘输入指令及操作数，格式为 命令[空格]数1[空格]数2
    如：
    add 15 25		//计算15+25的值，并返回结果
    sub 25 15		//计算25-15的值，并返回结果
    mux 3  5		//计算 3*5的值， 并返回结果
    div 25 5 		//计算25/5的值，并返回结果

题目要求
    1) 加、减、乘、除都需要封装为函数
    2) 编写有函数声明的头文件(有规范的预处理宏)
*/
    int num1;
    int num2;
    char buf[100] = {0};
    scanf("%s %d %d", buf, &num1, &num2);
    //    switch()//单个字符或者整数
    //    {
    //        case add

    //    }
    int ret = -1;
    if(0 == strcmp(buf, "add"))
    {
        ret = add(num1, num2);
    }else if(0 == strcmp(buf, "sub"))
    {
        ret = sub(num1, num2);
    }else if(0 == strcmp(buf, "mux"))
    {
        ret = mux(num1, num2);
    }else if(0 == strcmp(buf, "dive"))
    {
        ret = dive(num1, num2);
    }else
    {
        printf("invalide command\n");
    }
    printf("%d\n", ret);
}