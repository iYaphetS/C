#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main12()
{
    /*
 * ��д�����������GBK(UTF-8����)�ĺ����ַ����Ĺ��ܡ�
*/
    char s[] = "haue�������㿨��123ABC";

    int len = strlen(s);
    //��������
    for(int i = 0; i < len /2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;

    }
    //���ֵ�������
    for(int i = 0; i < len; i++)
        //Ϊʲô���ַ��������������أ���Ϊ�ַ����з����ĵ��ַ���һ���ֽڣ������������ַ�ʱ��ֻ��Ҫ����һ���ֽ�
    {
        if(s[i] < 0)//�ж��Ƿ��������ַ������ݣ���Ӧ��ֵ�Ǹ���
        {
            char temp = s[i];
            s[i] = s[i + 1];
            //s[i] = s[i + 2];//utf-8
            s[i + 1] = temp;
            //s[i + 2] = temp;
            i += 1;
            //i += 2;
        }
    }

    printf("%s", s);
    return 0;
}