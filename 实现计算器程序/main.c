#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int add(int num1, int num2)
{
    return num1 + num2;

}
int sub(int num1, int num2)
{
    return num1 - num2;
}
int mux(int num1, int num2)
{
    return num1 * num2;

}
int dive(int num1, int num2)
{
    if(num2 == 0)
    {
        printf("num2 can't zero\n");
    }else
        return num1 / num2;
}

int main21()
{
    /*
����������
    ���һ�������������Խ��мӡ������ˡ������㣬����ȫ������int����
Ҫ��Ӽ�������ָ�����������ʽΪ ����[�ո�]��1[�ո�]��2
    �磺
    add 15 25		//����15+25��ֵ�������ؽ��
    sub 25 15		//����25-15��ֵ�������ؽ��
    mux 3  5		//���� 3*5��ֵ�� �����ؽ��
    div 25 5 		//����25/5��ֵ�������ؽ��

��ĿҪ��
    1) �ӡ������ˡ�������Ҫ��װΪ����
    2) ��д�к���������ͷ�ļ�(�й淶��Ԥ�����)
*/
    int num1;
    int num2;
    char buf[100] = {0};
    scanf("%s %d %d", buf, &num1, &num2);
    //    switch()//�����ַ���������
    //    {
    //        case add

    //    }
    int ret = -1;
    if(0 == strcmp(buf, "add"))
    {
        ret = add(num1, num2);
    }else if(0 == strcmp(buf, "sub"))
    {
        ret = sub(num1, num2);
    }else if(0 == strcmp(buf, "mux"))
    {
        ret = mux(num1, num2);
    }else if(0 == strcmp(buf, "dive"))
    {
        ret = dive(num1, num2);
    }else
    {
        printf("invalide command\n");
    }
    printf("%d\n", ret);
}