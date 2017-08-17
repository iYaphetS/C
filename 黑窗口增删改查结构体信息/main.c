#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct information
{
    char *name;
    int age;
    char *adr;
}INFO;

void add_info(INFO **s, int *num)
{
    INFO *p = *s;
    int n = *num;

    //��pΪNULL�Ǵ˹��ܾ��൱��malloc
    INFO *q = realloc(p, (n + 1)*sizeof(INFO));
    if(q == NULL)
    {
        printf("q == NULL\n");
        return;
    }
    //memset(q, 0, (n + 1)*sizeof(INFO));
    //�ѿռ䣨���ǻ�������׷�����ݣ����ܵ���һ�����һ������
    char buf1[1024] = {0};
    char buf2[1024] = {0};

    scanf("%s %d %s", buf1, &q[n].age, buf2);

    q[n].name = calloc(1, sizeof(strlen(buf1)) + 1);
    q[n].adr = calloc(1, sizeof(strle(buf2)) + 1);

    strcpy(q[n].name, buf1);
    strcpy(q[n].adr, buf2);

    n++;

    *s = q;
    *num = n;

}
void print_info(INFO *s, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%s %d %s\n", s[i].name, s[i].age, s[i].adr);
    }
}

void free1_info(INFO **s, int num)
{
    INFO *p = *s;

    for(int i = 0; i < num; i++)
    {
        if(p[i].name != NULL)
        {
            free(p[i].name);
            p[i].name = NULL;
        }
        if(p[i].adr != NULL)
        {
            free(p[i].adr);
            p[i].adr = NULL;
        }

    }
    free(p);
    p = NULL;
}

int main29()
{
    /*
ʵ��һ�������ܴ���Ļ�Ͻ����������������Ϣ���¼�롣
     �ںڴ������ܹ�֧��print���� �����е��˵���Ϣ��ӡ
     �ٺڴ������ܹ�֧��exit����   �˳�����
     ��ʾ������������֮�䶼���ÿո�ֿ��ġ�
input:
     add tom  23  beijing
     add  jay    33  taiwan
     add andy  55  HK
input:
     print
output:
    tom  23  beijing
     jay    33  taiwan
     andy 55  HK
input:
     add jj 28 malaixiya
input:
     print
output:
     tom  23  beijing
     jay    33  taiwan
     andy 55  HK
     add jj 28 malaixiya
input:
     exit
     Ӧ�ó����˳� �ݰ�
*/


    INFO *ptr = NULL;
    char buf[100];
    int num = 0;
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        scanf("%s", buf);
        if(strncmp(buf, "add", 3) == 0)
        {
            add_info(&ptr, &num);
        }else if(strncmp(buf, "print", 5) == 0)
        {
            print_info(ptr, num);
        }else if(strncmp(buf, "exit", 4) == 0)
        {
            printf("�����˳�\n");
            break;
        }else
        {
            printf("invalid command\n");
        }

    }

    free1_info(&ptr, num);


    return 0;
}