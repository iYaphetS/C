#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct tech_info
{
    char name[64];
    int age;
}tinfo;
void write_file()//增
{
    FILE *fp = fopen("m.txt", "a");

    tinfo t = {0};//结构体缓冲区
    printf("please input num of tec:");
    int num = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        //memset(&m, 0, sizeof(t));
        printf("please input tecinfo:");
        scanf("%s %d", t.name, &t.age);

        fprintf(fp, "姓名=%s,年龄=%d\n", t.name, t.age);
    }

    fclose(fp);
}

void read_file()//查老师信息，并找到年龄第二大的老师
{
    FILE *fp = fopen("m.txt", "r");

    //
    char name[64] = {0};
    printf("please input name:");
    scanf("%s", name);
    char buf[1024] = {0};
    char tname[64] = {0};
    char tage[64] = {0};

    //
    int max = 0;
    char maxname[64] = {0};
    int smax = -1;
    char smaxname[64] = {0};
    while(fgets(buf, sizeof(buf), fp) != 0)
    {
        memset(buf, 0, sizeof(buf));
        sscanf(buf, "%*[^=]=%[^,]%*[^=]=%[^\n]", tname, tage);
        if(strncmp(name, "all", 3) == 0)
        {
            printf("姓名=%s,年龄=%s\n", tname, tage);
        }
        else if(strcmp(name, tname) == 0)
        {
            printf("姓名=%s,年龄=%s\n", tname, tage);
        }

        if(atoi(tage) > max)
        {
            smax = max;
            strcpy(smaxname, maxname);
            max = atoi(tage);
            strcpy(maxname, tname);
        }
        else if(atoi(tage) > smax)
        {
            smax = atoi(tage);
            strcpy(smaxname, tname);
        }
    }

    fclose(fp);
}
void delete_member()//删
{
    FILE *fp = fopen("m.txt", "r");

    char tname[64] = {0};
    char tage[64] = {0};
    char buf[1024] = {0};

    tinfo *m = NULL;
    int n = 0;
    tinfo *p = NULL;
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        sscanf(buf, "%*[^=]=%[^,]%*[^=]=%[^\n]", tname, tage);


        p = realloc(m, (n + 1)*sizeof(tinfo));
        strcpy(p[n].name, tname);
        strcpy(p[n].age, atoi(tage));
        n++;
    }

    m = p;
    fclose(fp);

    fp = fopen("m.txt", "w");

    char delname[64] = {0};
    printf("please input delname:");
    scanf("%s", delname);

    for(int i = 0; i < n; i++)
    {
        if(strcmp(delname, m[i].name) != 0)
        {
            fprintf(fp, "姓名=%s,年龄=%d\n", p[i].name, p[i].age);
        }
    }

    fclose(fp);
}
void updata_member()//改
{
    FILE *fp = fopen("m.txt", "r+");

    printf("please input oldname:");
    char oldname[64] = {0};
    scanf("%s", oldname);

    printf("please input newname:");
    char newname[64] = {0};
    scanf("%s", newname);

    char buf[1024] = {0};
    char tname[64] = {0};
    char tage[64] = {0};
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {

        sscanf(buf, "%*[^=]=%[^,]%*[^=]=%[^\n]", tname, tage);
        if(strcmp(oldname, tname) == 0)
        {
            strcpy(tname, newname);
            //文件指针已经移动到要更新的这一行的下一行
            //文件指针要会跳
            fseek(fp, -strlen(buf), SEEK_CUR);
            fprintf(fp, "姓名=%s,年龄=%d\n", tname, tage);
            break;
        }
    }

    fclose(fp);
}

int main35()
{
    /*
文件格式如下，行数未知
姓名=刘德华,年龄=50
姓名=安倍,年龄=30
姓名=张学友,年龄=45
姓名=苍老师,年龄=70

运行的结果是打印出这个文件中年龄第二大人的信息。
对文件能够进行 增 删 改 查
*/
    char command[64] = {0};

    while(1)
    {
        if(strncmp(command, "write", 5) == 0)
        {
            write_file();
        }
        else if(strncmp(command, "read", 4) == 0)
        {
            read_file();
        }
        else if(strncmp(command, "delete", 6) == 0)
        {
            delete_member();
        }
        else if(strncmp(command, "updata", 3) == 0)
        {
            updata_member();
        }
        else if(strncmp(command, "exit", 4) == 0)
        {
            break;
        }
    }

    return 0;
}