
#include <stdio.h>
#include <ctype.h>

int main8()
{
    /*
����һ���ַ���\(����Ϊn\)
ͳ�����г��ֵĴ�д��ĸ��Сд��ĸ�������ַ����հ��ַ�\(' ','\n'��'\t'��\)�ȵ�������
*/
    char s[] = "2267s j54u wj 398\t\n";
    int number[10] = {0};//����0-9�������ֳ��ֵĴ���
    int count1 = 0, count2 = 0, count3 = 0;//�ֱ������д��ĸСд��ĸ�հ��ַ��ĸ���
    int len = strlen(s);

    for(int i = 0; i < len; i++)
    {
        if(islower(s[i]))//Сд��ĸ
            count1++;
        if(isupper(s[i]))//��д��ĸ
            count2++;
        if(isdigit(s[i]))
            //if(s[i] >= '0' && s[i] <= '9')
            number[s[i] - '0']++;
        //if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        if(isspace(s[i]))//�հ��ַ�
            count3++;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("number[%d] = %d\n", i, number[i]);
    }
    printf("%d %d %d\n", count1, count2, count3);
    return 0;
}