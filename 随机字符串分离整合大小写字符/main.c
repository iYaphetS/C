#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void TransString(char *pstr,char len)
{
   //����һð����������ɸѡ��ǰ����ַ��Ǵ�д����һ���ַ���Сд���ͽ�������
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(isupper(pstr[j]) && islower(pstr[j + 1]))
            {
                char temp = pstr[j];
                pstr[j] = pstr[j + 1];
                pstr[j + 1] = temp;
            }

        }
    }
    //�����������ַ�����������д�ַ��������ŵ���ʱ�����У���������ַ���������ǰ�ƶ�
    //Ȼ�����ŵ��ַ�β��
//    int num = 0;
//    char *p = pstr;
//    while(*p)
//    {
//        if(islower(*p))
//            num++;
//        p++;
//    }
//    p = pstr;
//    int count = 0;
//    while(*p)
//    {
//        if(isupper(*p))
//        {
//            char temp = *p;
//            for(int i = 0; i < len - count - 1; i++)
//                p[i] = p[i + 1];
//            p[len - count - 1] = temp;
//        }
//        else
//        {
//            p++;
//            count++;//����Сд��ĸ�ĸ���
//        }
//        if(count == num)
//            break;
//    }

}

int main42()
{
/*
��һ������γɵ��ַ����еĴ�д��ĸ����ԭ����˳����õ��ַ�����벿��
Сд��ĸ�����ַ���ǰ�벿�֡�
���� AbCdefGHijLKdfkjf
     ACGHLKbdefijdfkjf
����ԭ������ int TransString(char *pstr,char len);
ʵ�������������ַ�������ת��  ��ʾ����ռ価���١�
*/
    char buf[100] = "AbCdefGHijLKdfkjf";
    int len = strlen(buf);
    TransString(buf, len);

    printf("%s\n", buf);

}