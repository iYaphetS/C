#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//---------------------
typedef struct man_info
{
    char *name;
    int  age;
}info;

void inupt_info(info **s, int num)
{
    info *p = *s;
    p = calloc(num, sizeof(info));
    if(p == NULL)
    {
        printf("p == NULL\n");
        return;
    }

    for(int i = 0; i < num; i++)
    {
        char buf[1024] = {0};
        scanf("%s %d", buf, &p[i].age);

        p[i].name = calloc(1, sizeof(strlen(buf)) + 1);
        if(p[i].name == NULL)
        {
            printf("p[i].name == NULL\n");
            break;
        }
        strcpy(p[i].name, buf);
    }
    *s = p;//�����ٵĶѿռ���׵�ַ����*s��*sҲָ����Ƭ�ռ�
    return;


}
void output_info(info *s, int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%s %d\n", s[i].name, s[i].age);
    }

}

void free_info(info **s, int num)
{
    info *p = *s;

    for(int i = 0; i < num; i++)
    {
        if(p[i].name != NULL)
        {
            free(p[i].name);
            p[i].name = NULL;
        }
    }
    free(p);
    p = NULL;
}

int main28()
{
    /*    ���ô������ơ�
    ����Ļ������һ���� n
    Ȼ������n���˻�����Ϣ(���� ���)
         ���������֮��  �����е���Ϣȫ����ӡ��
         3
         zhangsan 170
         lisi 190
         wanger 175

         ��1���˵�����:zhangsan ���:170
         ��2���˵�����:lisi     ���:190
         ��1���˵�����:wanger   ���:175
    Ҫ��:ʹ��������ʽ�Ľṹ��
         struct Info_t
    {
        char *name;
        int  age;
      int num;
      };
      */
    int num;
    scanf("%d", &num);

    info *ptr = NULL;
    inupt_info(&ptr, num);

    output_info(ptr, num);

    free_info(&ptr, num);


    return 0;
}