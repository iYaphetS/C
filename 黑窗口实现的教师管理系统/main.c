#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct man_t
{
    char name[128];
    int age;

}man;

void open_file(man **s, int *pn)
{
    char filename[64];
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");

    /*
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int num = size / sizeof(man);
    man *p = calloc(num, sizeof(man));
    fread(p, sizeof(man), num, fp);
 */
    int n = *pn;
    man m = {0};
    man *p = NULL;
    while(fgets(&m, sizeof(man), fp) != NULL)
    {
        p = realloc(*s, (n + 1)*sizeof(man));
        if(p == NULL)
            break;
        memcpy(p + n, &m, sizeof(man));
        //sprintf(p + n, "%s %d", m.name, m.age);
        printf("%s %d", p[n].name, p[n].age);
        n++;
    }

    fclose(fp);
    *s = p;
    *pn = n;
}

void print_file(man *m, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s %d\n", m[i].name, m[i].age);
    }
}

void add_file(man **s, int *pn)
{
    int n = *pn;
    man *p = realloc(*s, (n + 1)*sizeof(man));
    if(p == NULL)
        return;
    scanf("%s %d", p[n].name, &p[n].age);

    n++;
    *s = p;
    *pn = n;

}
void save_file(man *m, int n)
{
    char filename[64];
    scanf("%s", filename);
    FILE *fp = fopen(filename, "wb");

    fwrite(m, sizeof(man), n, fp);

    fclose(fp);

}

int main31()
{
    /*
���һ����ʦ��Ϣ����ϵͳ��
�ܹ�֧��
    open file��ʾ������ļ��е����ݼ����ڴ���
    add name age address  �ܹ������Ϣ
    print��ӡ�����Ѿ����������
    save file��ʾ���ڴ��е�����д�뵽ָ���ļ���
����ָ�
*	���Խ�ϵ�һ����Ŀ�����ݵı༭��ϵ��ڶ����С�

    input��open a.txt  ����a.txt�е����ݵ��ڴ�
    input��print       �������ڴ��е����ݴ�ӡ����
    input: add zhangsan 28 beijing    ��zhangsan����Ϣ����ڴ�
    input: print
                        �������Ϣ��Ӧ�ú�����������Ϣ
    input: save b.txt   ���ڴ������е����ݴ洢���ļ�b.txt��
*/

    //    FILE *fp = fopen("a.txt", "wb");
    //    man m1;
    //    scanf("%s %d", m1.name, &(m1.age));
    //    fwrite(&m1, sizeof(man), 1, fp);
    //    fclose(fp);

    man *m = NULL;
    char command[64] = {0};
    int n = 0;

    while(1)
    {
        scanf("%s", command);
        if(strncmp(command, "open", 4) == 0)
        {
            open_file(&m, &n);
        }
        else if(strncmp(command, "print", 5) == 0)
        {
            print_file(m, n);
        }
        else if(strncmp(command, "add", 3) == 0)
        {
            add_file(&m, &n);
        }
        else if(strncmp(command, "save", 4) == 0)
        {
            save_file(m, n);
        }
        else if(strncmp(command, "exit", 4) == 0)
        {
            break;
        }
        else
        {
            printf("invalide command\n");
        }

    }

    free(m);

    return 0;
}