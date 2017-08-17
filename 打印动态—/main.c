#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    //- \ | /
    while(1)
    {
        //转义字符 \\ \r \n \b \t \0
        printf("%s", "-");
        Sleep(1);//毫秒单位
        printf("%c", '\b');//退格

        printf("%c", '\\');
        Sleep(1);
        printf("%c", '\b');

        printf("%s", "|");
        Sleep(1);
        printf("%c", '\b');

        printf("%s", "/");
        Sleep(1);
        printf("%c", '\b');

    }
    return 0;
}