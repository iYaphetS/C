#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main2()
{
    //- \ | /
    while(1)
    {
        //ת���ַ� \\ \r \n \b \t \0
        printf("%s", "-");
        Sleep(1);//���뵥λ
        printf("%c", '\b');//�˸�

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