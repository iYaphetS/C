#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


/*�����������
 * 1.��һ�ַ����Ǳ����ɱ��ж�
 * --------------------------------
    srand((unsigned)time(NULL));

    for(int i = 0; i < 6; i++)
    {
        randnum[i] = rand() % 33 + 1;
        //����������ַ���randnum[i] = rand() % 33 + 1 + '0';
        for(int j = 0; j < i; j++)
        {
            if(randnum[i] == randnum[j])
            {
                i--;
                break;
            }
        }
    }
    ---------------------------------------
    2.�ڶ��ַ����������ɣ����ж�
int dif_num(int *a, int len)
{
    int ret = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int main()
{
    while(1)
    {
        srand((unsigned)time(NULL));

        for(int i = 0; i < 6; i++)
        {
            randnum[i] = rand() % 33 + 1;
            //����������ַ���randnum[i] = rand() % 33 + 1 + '0';
        }
        if(dif_num(randnum, len) == 0)
            break;
    }
}
 --------------------------------------------
*/
int difnumOFstr(char *buf)//
{
    int ret = 0;
    int n = strlen(buf);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(buf[i] == buf[j])//
            {
                ret = 1;//����ͬ�ַ�
                break;
            }
        }

    }
    return ret;
}
int main38()
{
    /*
���������һ��4λ��ͬ������������û������жϺϷ��ԣ�4λ���ظ��Ľ����ֵ������������������ʾ���
A:���ֶ�λ�ö�
B:���ֶ�λ�ò���
*/

    char a[100] = {0};//��ż�������������ת�ɵ��ַ���
    srand((unsigned)time(NULL));

    for(int i = 0; i < 4; i++)
    {
        a[i] = rand() % 10 + '0';
        //ÿ����һ��������ǰ������������бȽ��Ƿ���ͬ
        //��ͬi--�������������
        for(int j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                i--;
                break;
            }
        }
    }
    printf("%s\n", a);
    char b[100] = {0};//����û�������������ַ���
    char p[100] = {0};//��¼״̬A B,ÿ�μ��һ���ַ���Ҫд��һ��״̬
    int index = 0;
    while(1)
    {
        memset(b, 0, sizeof(b));//��Ϊ������ÿ��ѭ����Ҫ���
        memset(p, 0, sizeof(p));
        index = 0;

        printf("plese input 4 numbers(0-9):");
        scanf("%s", b);
        int flag = 0;
        int len = strlen(b);

        //�ж����Ƿ�Ϸ�
        for(int i = 0; i < len; i++)
        {
            if(len != 4 || difnumOFstr(b) == 1 || isdigit(b[i]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("input num error\n");
        }
        else
        {
            for(int i = 0; i < 4; i++)
            {
                if(b[i] == a[i])
                {
                    p[index++] = 'A';
                }
                else
                {
                    for(int j = 0; j < 4; j++)
                    {
                        if(b[i] == a[j])
                            p[index++] = 'B';
                    }
                }
            }

            if(strcmp(p, "AAAA") == 0)
            {
                printf("so good!number is %s\n", b);
                break;
            }
            else if(p[0] == '\0')
            {
                printf("so bad\n");
            }
            else if(p)
            {
                printf("%s\n", p);
            }
        }

    }

    return 0;
}