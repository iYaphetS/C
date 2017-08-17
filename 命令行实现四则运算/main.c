#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int calc(int num1, char c, int num2)
{
    int ret = 0;
    switch(c)
    {
    case '+':
        ret = num1 + num2;
        break;
    case '-':
        ret = num1 - num2;
        break;
    case '*':
        ret = num1 * num2;
    case '/':
        if(num2 == 0)
        {
            printf("error num2\n");
            exit(-1);
        }
        ret = num1 / num2;
        break;
    default:
        printf("invalide operator\n");
        break;
    }

}

int main13(int argc, char **args)
{
    /*
使用main函数参数完成四则运算器。
编译指令：gcc -o app main.c app.c
效果如下：
./app 12 + 13
12+13=25

./app 13 - 13
13-13=0

./app 12 \* 10
12*10=120

./app 120 / 60
120/6=20

./app 12 ^ 2
error invalid operator
*/
    if(argc < 4)
        printf("参数不足，请输入%s 数1 运算符 数2\n", args[0]);
    //scanf("%s %s %s", args[1], args[2], args[3]);
    int ret = calc(atoi(args[1]), args[2][0], atoi(args[3]));

    printf("output: %d\n", ret);
    return 0;
}