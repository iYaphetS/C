#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef unsigned long ul;

ul Fibonacci_recursive(int n)
{
    if(n == 1 ||n == 2)
    {
        return 1;
    }
    else
    {
        return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
    }
}
ul Fibonacci_unrecursive(int n)
{
    ul a;
    ul b;
    ul r;

    if(n == 1 || n == 2)
    {
        r = 1;
    }
    else
    {
        a = r = 1;
        while(n > 2)
        {
            b = a;//b ----f(n - 2)
            a = r;//a-----f(n - 1)
            r = a + b;
            n--;
        }

    }
    return r;
}

int main43()
{
/*
1.斐波纳契数列的递归代码实现
2.斐波纳契数列的非递归代码实现
*/
    int n;
    ul ret;
    printf("please input num:");
    scanf("%d", &n);
    //ret = Fibonacci_recursive(n);
    ret = Fibonacci_unrecursive(n);
    printf("%lu", ret);
    return 0;
}