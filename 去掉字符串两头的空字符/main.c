#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void format(char *str)//ȥ�����ߵĿհ��ַ�
{
    char *t = NULL;
    char *p = str;
    char *q = str + strlen(str) - 1;

    while(isspace(*p))
        p++;
    while(isspace(*q))
        q--;
    while(p <= q)
        *t++ = *p++;//��p-q����ַ���������tָ��Ŀռ�
    *t = '\0';
    //strncpy(t, p);
    //t[q - p + 1] = '\0'

    return;
}

int main14()
{
    /*
 * ȥ��һ���ַ��������ߵĿ��ܵĿհ��ַ�(' ','\t','\n')��
char buf[] = "        			hello heima	\n";
����֮����ַ�����"hello heima"

*/
    //�˷�������һ������ָ�룬ͨ������ָ��p�ı�ԭָ��sָ�������
    //�����װΪ������Ҫ������ָ����Ϊָ���ָ�����˸ı�
    char s[] = "  hello hah heihei zensidou  \n   \r  \t";

    char *p = s;

    p = p + strlen(s) - 1;
    while(isspace(*p))
    {
        *p = '\0';
        p--;
    }
    p = s;
    while(isspace(*p))
        p++;

    printf("(%s)\n", p);//��ӡ����pָ������ݣ�ָ�����˸ı�
    return 0;
}