#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main20()
{
    /*
将一串歌词切割为单词
*/
    char s[] = "On success, the total number of characters written is returned. \
            This count does not include the additional null-character automatically \
            appended at the end of the string. \
            On failure, a negative number is returned.";
            char *p = strtok(s, " ,\\.");

    while(p)//
    {
        printf("%s\n", p);
        p = strtok(NULL, " ,\\.");
    }
    return 0;
}