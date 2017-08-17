#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void word_reverse(char *s)//单词（子串）逆置
{
    //通过辅助指针t对原来的指针s指向的内容进行修改
    char *t = s;
    char *p = NULL;//子串头指针
    char *q = NULL;//子串尾指针

    while(*t)
    {
        while(islower(*t) || isupper(*t))
        {
            if(p == NULL)
                p = t;
            q = t;
            t++;
        }
        while(p < q)
        {
            char temp = *p;
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
        p = q = NULL;
        t++;
    }
    return;
}

int main15()
{
    /*
    编写一个函数将指定字符串按照以下规则逆置。
    char buf[] = "hello world itheima good";
    逆置之后的结果为"olleh dlrow amiehti doog";
    将字符串中的单词逆置 ，其余的保持不变。
*/
    char s[] = "     hello  hh,,,,,,,ahh kkk, jaw   dog  ";

    word_reverse(s);

    printf("%s\n", s);
}