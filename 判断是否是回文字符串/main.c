#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int is_palindrome(const char *str)
{
    int ret = 0;
    int len = strlen(str);
    char *p = str;
    char *q = str + len -1;
    while(p < q)
    {
        if(*p != *q)
            ret = -1;
        p++;
        q--;
    }

    return ret;
}

int main19()
{
    /*
    ����һ���ַ������ж����Ƿ��ǻ����ַ�����(���ģ��������ͷ�����һ������abcba)
    ��ʵ��һ����������������ܣ���д����Ӧ�Ĳ��Դ��������֤��

    �ο�����ԭ��:int is_palindrome(const char *str);
    ��������ֵ  :����Ƿ���0�����򷵻ط�0
*/
    char s[] = "122321";

    int ret = is_palindrome(s);

    printf("%d\n", ret);
    return 0;
}