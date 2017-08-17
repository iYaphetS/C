#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void swap1(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int *a, int *b)
{
    int c = *a + *b;
    *a = c - *a;
    *b = c - *a;
}

void swap3(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    /*
�����������������ַ���
*/
    int a = 3, b = 8;
    //swap1(&a, &b);
    //swap2(&a, &b);
    swap3(&a, &b);

    printf("a = %d, b = %d\n", a, b);
}