#include <stdio.h>


int isOddNumber(unsigned num)//�ж��Ƿ�Ϊ����
{
    int ret;
    if(num % 2)
        ret = 0;
    else
        ret = 1;

    return ret;
}

int main10()
{
    /*
������
    ����ԭ�� int isOddNumber(unsigned int number);
    �������� �жϲ���number�Ƿ������� �����ж��������Ƿ��ܹ���2������
    ��������ֵ �������������0;���������������1
*/
    unsigned num;
    scanf("%d", &num);

    int ret = isOddNumber(num);
    if(ret == 0)
        printf("����\n");
    else
        printf("ż��\n");

}