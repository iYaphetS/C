#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void word_reverse(char *s)//���ʣ��Ӵ�������
{
    //ͨ������ָ��t��ԭ����ָ��sָ������ݽ����޸�
    char *t = s;
    char *p = NULL;//�Ӵ�ͷָ��
    char *q = NULL;//�Ӵ�βָ��

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
    ��дһ��������ָ���ַ����������¹������á�
    char buf[] = "hello world itheima good";
    ����֮��Ľ��Ϊ"olleh dlrow amiehti doog";
    ���ַ����еĵ������� ������ı��ֲ��䡣
*/
    char s[] = "     hello  hh,,,,,,,ahh kkk, jaw   dog  ";

    word_reverse(s);

    printf("%s\n", s);
}